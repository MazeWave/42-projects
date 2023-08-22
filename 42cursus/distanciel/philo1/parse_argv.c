/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:59:55 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/22 18:50:16 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Checks if the argc number is correct
Checks if the arguments isnt a number or a '-' or a '+'
*/

int	parse_argv(t_rules *rules)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (rules->argc < 5 || rules->argc > 6)
		return (1);
	while (i < rules->argc)
	{
		if (rules->argv[i][0] < '0' || rules->argv[i][0] > '9')
		{
			if (rules->argv[i][0] != '+')
				return (1);
		}
		while (rules->argv[i][j] != '\0')
		{
			if (rules->argv[i][j] < '0' || rules->argv[i][j] > '9')
				return (1);
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}
