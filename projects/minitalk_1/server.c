/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:04:07 by ldalmass          #+#    #+#             */
/*   Updated: 2023/03/13 18:46:20 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str;

static void	handler(int sig)
{
	ft_printf("entering handler\n");
	int	str_len;
	int	i;

	i = 0;
	str_len = 0;
	if (sig == 29)
	{
		ft_printf("enterring if 29\n");
		str_len = str_len + 1;
		write(1, "1", 1);
		ft_printf("Len = %d\n", str_len);
		ft_printf("exiting if 29\n");
	}
	if (sig == 30 || ++i <= str_len)
	{
		ft_printf("0\n");
		g_str[i] = '0';
	}
	if (sig == 31 || ++i <= str_len)
	{
		ft_printf("1\n");
		g_str[i] = '1';
	}
	if (sig < 29)
	{
		ft_printf("\nServer closed.\n");
		exit(0);
	}
	ft_printf("exiting handler\n");
	return ;
}

int	main(void)
{
	char	*pid;
	int		i;

	i = 0;
	g_str = "HELLO\0";
	pid = (ft_itoa(getpid()));
	ft_printf("Listening on PID : %s\n", pid);
	signal(29, handler);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	signal(SIGINT, handler);
	while (1)
		pause();
	return (0);
}
