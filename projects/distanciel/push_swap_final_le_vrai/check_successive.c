/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_successive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass < ldalmass@student.42nice.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:55:24 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/06 19:47:40 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_successive(t_ps *ps)
{
	int	i;

	i = 1;
	while (i < ps->argc)
	{
		if (ps->argv[i][0] == '\0')
			return (1);
		if (ps->argv[i][0] == '+' || ps->argv[i][0] == '-')
		{
			if ((ps->argv[i][1] == '\0'
				|| ps->argv[i][1] == '+' || ps->argv[i][1] == '-'))
				return (1);
		}
		i++;
	}
	return (0);
}
