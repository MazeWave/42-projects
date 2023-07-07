/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:32:54 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/27 20:45:03 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_types(t_ps *ps)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ps->argc)
	{
		ft_printf("      TYPE argv : %s\n", ps->argv[i]);
		while (ps->argv[i][j] != '\0')
		{
			if ((ps->argv[i][j] < '0' || ps->argv[i][j] > '9')
			&& ps->argv[i][j] != '-')
			{
				ft_printf("ERROR TYPE	: I = %d, J = %d, faulty letter : %c\n", i, j, ps->argv[i][j]);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
