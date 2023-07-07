/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:38:53 by ldalmass          #+#    #+#             */
/*   Updated: 2023/04/27 00:12:28 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig)
{
	static char	*str;
	static int	temp = 0;
	static int	i = 8;

	if (!str)
		str = ft_strdup("");
	if (sig == 31)
		temp |= (1 << (i - 1));
	i = i - 1;
	if (i == 0)
	{
		if (temp == 0)
		{
			ft_putstr_fd(str, 1);
			//ft_printf("%s", str);
			free(str);
			str = ft_strdup("");
			write(1, "\n", 1);
		}
		else
			str = ft_strjoin(str, (char *)&temp);
		i = 8;
		temp = 0;
	}
	return ;
}

int	main(void)
{
	char		*pid;
	int			i;

	i = 0;
	pid = (ft_itoa(getpid()));
	ft_printf("--- Listening on PID : %s ---\n", pid);
	signal(30, handler);
	signal(31, handler);
	free(pid);
	while (1)
	{
		pause ();
		//fflush(stdout);
		//system("LEAKS server");
	}
	return (0);
}
