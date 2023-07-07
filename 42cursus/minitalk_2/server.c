/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:38:53 by ldalmass          #+#    #+#             */
/*   Updated: 2023/04/11 18:00:05 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*g_str[3];

static void	send_char(void)
{
	int	i;
	int	j;
	int	dec;

	i = 0;
	j = 6;
	dec = 0;
	while ((char *)g_str[2][i] != '\0')
	{
		if (g_str[2][i] == 1)
			dec = dec + (1 << j);
		i = i + 1;
		j = j - 1;
	}
	if (dec == 0)
	{
		write(1, "\0", 1);
		return ;
	}
	write(1, "dec = ", 6);
	ft_printf("\n%d\n", dec);
	return ;
}

static void	data_handler(int sig)
{
	if (g_str[2] == '6')
	{
		write(1, "Sending packet : ", 16);
		write(1, &g_str[2], 7);
		write(1, "\n", 1);
		send_char();
		g_str[1] = g_str[1] - 1;
		g_str[2] = '0';
	}
	if (sig == 30)
	{
		g_str[2] = '0';
		write(1, "0", 1);
	}
	if (sig == 31)
	{
		g_str[2] = '1';
		write(1, "1", 1);
	}
	write(1, "HERE\n", 5);
	g_str[2] = g_str[2] + 1;
	return ;
}

//g_str[0][0] = process state value (or in what step the program is).
//g_str[1][0] = lenght of the string, max is 2147483647 for now.
//g_str[2][0 <-> 6] (total 7) = packet size for a single character.
static void	handler(int sig)
{
	if (sig == 30 && g_str[0][0] == 0) //get lenght.
		g_str[1][0] = g_str[1][0] + 1;
	if (sig == 31 && g_str[0][0] == 0) //changing state to 1 (0 -> 1).
	{
		ft_printf("len = %d\n", g_str[1]);
		g_str[0] = 1;
		g_str[2] = 0;
		g_str[3] = 0;./se
	}
	//i = i + 1;
	if ((sig == 30 || sig == 31) && g_str[0][0] == 1) //receive bits (7 * lenght).
		data_handler(sig);
	if (g_str[1][0] == 0 && g_str[0][0] == 1)
	{
		write(1, "Resetting state\n", 16); //resetting state  back to 0 (1 -> 0).
		g_str[0] = 0;
		g_str[1] = 0;
		g_str[2] = 0;
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
	g_str[0] = ft_calloc(sizeof(int) * 1, 1);  //state   [0 - 1]
	g_str[1] = ft_calloc(sizeof(int) * 1, 1);  //lenght  [0 - 2147483647]
	g_str[2] = ft_calloc(sizeof(char) * 7, 1); //packet  ['1','1','0','0','0','0','1'] = 'a'
	if (!g_str)
		return (0);
	g_str[0] = 0;
	g_str[1] = 0;
	g_str[2] = '\0';
	signal(30, handler);
	signal(31, handler);
	while (1)
		pause ();
	ft_printf("--- PROGRAM EXITED UNEXPECTEDLY ---\n");
	return (0);
}
