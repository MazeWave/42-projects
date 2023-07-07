/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:38:51 by ldalmass          #+#    #+#             */
/*   Updated: 2023/05/02 23:49:48 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	handler(int sig)
{
	if (sig < 0)
		return ;
	return ;
}

static void	send_letter(pid_t pid, char c)
{
	char	*letter;
	int		j;

	letter = malloc(sizeof(char) * 8);
	if (!letter)
		return ;
	j = 0;
	if (letter)
		free(letter);
	letter = ft_dec_to_bin(c);
	usleep(200);
	while (j < 8)
	{
		usleep(200);
		if (letter[j] == '1')
			kill(pid, 31);
		else
			kill(pid, 30);
		j++;
	}
	free(letter);
	return ;
}

static int	pre_processor(char *pid, char *str)
{
	pid_t	real_pid;
	int		len;
	int		i;

	real_pid = atoi(pid);
	len = ft_strlen(str);
	i = -1;
	if (real_pid <= 0)
		ft_printf("INVALID PID.\n");
	if (!str)
		ft_printf("BAD OR EMPTY STRING.\n");
	else
	{
		while (++i <= len)
			send_letter(real_pid, str[i]);
	}
	signal(30, handler);
	pause();
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
