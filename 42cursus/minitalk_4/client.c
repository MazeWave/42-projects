/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:38:51 by ldalmass          #+#    #+#             */
/*   Updated: 2023/04/27 00:14:25 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_string(pid_t pid, char *str, int i, int lenn)
{
	char	*packet;
	int		j;

	packet = malloc(sizeof(char) * 8);
	if (!packet)
		return ;
	while (++i <= lenn)
	{
		j = 0;
		if (packet)
			free(packet);
		packet = ft_dec_to_bin(str[i]);
		usleep(500);
		while (j < 8)
		{
			usleep(500);
			if (packet[j] == '1')
				kill(pid, 31);
			else
				kill(pid, 30);
			j = j + 1;
		}
	}
	free(packet);
	return ;
}

static int	pre_processor(char *pid, char *str)
{
	pid_t	real_pid;
	int		lenn;

	real_pid = atoi(pid);
	lenn = ft_strlen(str);
	if (real_pid <= 0)
		ft_printf("INVALID PID.\n");
	if (!str)
		ft_printf("BAD OR EMPTY STRING.\n");
	else
		send_string(real_pid, str, -1, lenn);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		pre_processor(argv[1], argv[2]);
	else
	{
		ft_printf("Error with your arguments.\n");
		ft_printf("Usage : ./client [server PID] [message]\n");
		return (0);
	}
	//system("LEAKS client");
	return (0);
}
