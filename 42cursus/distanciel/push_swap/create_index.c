/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass < ldalmass@student.42nice.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:59:38 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/27 03:21:26 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_value(t_ps *ps, int min)
{
	t_ps	*temp;

	temp = ps;
	while (temp)
	{
		if (temp->value <= min && temp->index < 1)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

void	create_index(t_ps *ps, int i)
{
	t_ps	*temp;
	int		min;

	temp = ps;
	min = find_min_value(temp, 2147483647);
	while (temp)
	{
		min = find_min_value(temp, min);
		if (temp->value <= min && temp->index < 1)
		{
			temp->index = i;
			i++;
			create_index(ps, i);
		}
		temp = temp->next;
	}
	return ;
}
