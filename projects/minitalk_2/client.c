/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:38:51 by ldalmass          #+#    #+#             */
/*   Updated: 2023/04/05 15:21:24 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str;

static void	send_len(pid_t pid)
{
	int		str_len;
	int		i;

	str_len = ft_strlen(g_str);
	i = 0;
	while (str_len >= i)
	{
		kill(pid, 30);
		usleep(10);
		i = i + 1;
	}
	return ;
}

static void	send_string(pid_t pid)
{
	char	*packet;
	int		i;
	int		j;

	i = 0;
	packet = malloc(sizeof(char) * 8);
	if (!packet)
		return ;
	while (g_str[i] != '\0')
	{
		j = 0;
		packet = ft_dec_to_bin(g_str[i]);
		while (j < 8)
		{
			if (packet[j] == '1')
				kill(pid, 31);
			else
				kill(pid, 30);
			j = j + 1;
		}
		i = i + 1;
	}
	return ;
}

static int	pre_processor(char *pid)
{
	pid_t	real_pid;

	real_pid = atoi(pid);
	if (real_pid <= 0)
	{
		ft_printf("INVALID PID.\n");
		return (0);
	}
	if (!g_str)
	{
		ft_printf("BAD OR EMPTY STRING.\n");
		return (0);
	}
	send_len(real_pid);
	usleep(20);
	kill(real_pid, 31);
	usleep(20);
	send_string(real_pid);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error with your arguments.\n");
		ft_printf("Usage : ./client [server PID] [message]\n");
		return (0);
	}
	else
	{
		g_str = argv[2];
		ft_printf("%s\n", g_str);
		pre_processor(argv[1]);
	}
	return (0);
}
