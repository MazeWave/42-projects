/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:38:53 by ldalmass          #+#    #+#             */
/*   Updated: 2023/05/03 01:34:30 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	reduce_your_expectation(int pid, void *useless, siginfo_t *info)
{
	(void)useless;
	if (info->si_pid)
		pid = info->si_pid;
	return (pid);
}

static char	*reduce_again(int pid, char *str)
{
	ft_putstr_fd(str, 1, pid);
	free(str);
	str = ft_strdup("");
	return (str);
}

static void	handler(int sig, siginfo_t *info, void *useless)
{
	static char	*str;
	static char	temp = 0;
	static int	i = 8;
	static int	pid = 0;

	pid = reduce_your_expectation(pid, useless, info);
	if (!str)
		str = ft_strdup("");
	if (sig == 31)
		temp |= (1 << (i - 1));
	if (--i == 0)
	{
		if (temp != 0)
			str = ft_strjoin(str, &temp);
		else
			str = reduce_again(pid, str);
		i = 8;
		temp = 0;
	}
	usleep(75);
	kill(pid, 30);
	return ;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	ft_printf("--- Listening on PID : %d ---\n", getpid());
	sigaction(30, &sa, NULL);
	sigaction(31, &sa, NULL);
	while (1)
	{
		pause ();
		//fflush(stdout);
		//system("LEAKS server");
	}
	return (0);
}
