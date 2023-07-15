/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 02:46:53 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 02:47:50 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_ps *ps)
{
	t_ps	*temp;
	int		max;

	temp = ps;
	max = temp->value;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

void	push_max(t_ps **ps_a, t_ps **ps_b)
{
	int	max;

	max = find_max(*ps_a);
	while ((*ps_a)->value != max)
		ra(ps_a, 1);
	pb(ps_a, ps_b);
	return ;
}
