/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:54:29 by ldalmass          #+#    #+#             */
/*   Updated: 2023/03/08 19:51:20 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str;

static void	send_lenght(pid_t pid)
{
	int		i;

	i = ft_strlen(g_str);
	while (i > 0)
	{
		ft_printf("%d\n", i);
		kill(pid, 29);
		i = i - 1;
	}
	return ;
}

/* static void	send_sig(pid_t pid)
{
	char	*bin;
	int		i;
	int		j;

	i = 0;
	j = 0;
	bin = ft_calloc(7, 1);
	if (!bin)
		return ;
	while (g_str[i] != '\0')
	{
		bin = ft_itoa(ft_bin(ft_atoi(&(g_str[i])), 0));
		while (bin[j] != '\0')
		{
			if (bin[j] == '0')
				kill(pid, 31);
			if (bin[j] == '1')
				kill(pid, 30);
			usleep(20);
			j = j + 1;
		}
		j = 0;
	}
	return ;
} */

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
		ft_printf("BAD STRING.\n");
		return (0);
	}
	send_lenght(real_pid);
	//send_sig(real_pid);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error with your arguments");
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
