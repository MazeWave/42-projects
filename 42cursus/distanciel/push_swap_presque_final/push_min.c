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

static int	roll_number(t_ps *stack, int min)
{
	t_ps	*temp;
	int		i;

	i = 0;
	temp = stack;
	while (temp->index != min)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	push_min(t_ps **ps_a, t_ps **ps_b)
{
	int	min_index;
	int	roll;
	int	i;

	i = 0;
	min_index = find_min(*ps_a);
	roll = roll_number(*ps_a, min_index);
	if (roll < (stack_len(*ps_a) / 2))
	{
		while (i < roll)
		{
			ra(ps_a, 1);
			i++;
		}
	}
	else
	{
		while (i < (stack_len(*ps_a) - roll))
		{
			rra(ps_a, 1);
			i++;
		}
	}
	pb(ps_a, ps_b);
	return ;
}

/*void	push_min(t_ps **ps_a, t_ps **ps_b)
{
	int	index;

	index = find_min(*ps_a);
	if (index < (stack_len(*ps_a) / 2))
	{
		while ((*ps_a)->index != index)
			ra(ps_a, 1);
	}
	else
	{
		while ((*ps_a)->index != index)
			rra(ps_a, 1);
	}
	pb(ps_a, ps_b);
	return ;
}*/
