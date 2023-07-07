/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killtest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:52:20 by ldalmass          #+#    #+#             */
/*   Updated: 2023/03/13 18:33:51 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

char	*g_str;

static void	send(pid_t pid)
{
	kill(pid, 29);
	printf("Signal envoyé\n");
	return ;
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Error with your arguments");
		return (0);
	}
	else
	{
		g_str = argv[2];
		printf("%s\n", g_str);
		send(atoi(argv[1]));
	}
	return (0);
}
