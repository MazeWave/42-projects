/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 02:24:54 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 04:12:18 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_ps *ps)
{
	t_ps	*temp;
	t_ps	min;

	temp = ps;
	min = *temp;
	while (temp)
	{
		if (temp->value < min.value)
		{
			min.value = temp->value;
			min.index = temp->index;
		}
		temp = temp->next;
	}
	return (min.index);
}

void	push_min(t_ps **ps_a, t_ps **ps_b)
{
	int	index;

	index = find_min(*ps_a);
	while ((*ps_a)->index != index)
		ra(ps_a, 1);

	pb(ps_a, ps_b);
	return ;
}
