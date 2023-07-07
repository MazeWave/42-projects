/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:38:53 by ldalmass          #+#    #+#             */
/*   Updated: 2023/04/11 23:24:33 by ldalmass         ###   ########.fr       */
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
			free(str);
			str = NULL;
			write(1, "\n", 1);
			kill(-1, 31);
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
	while (1)
		pause ();
	ft_printf("--- PROGRAM EXITED UNEXPECTEDLY ---\n");
	return (0);
}
