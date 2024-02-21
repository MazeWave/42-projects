/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:33:21 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 04:52:09 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smol_sort(t_ps **pa)
{
	int	a;
	int	b;
	int	c;

	a = (*pa)->value;
	b = (*pa)->next->value;
	c = (*pa)->next->next->value;
	if (a < b && b < c)
		return ;
	else if (a < b && b > c)
	{
		sa(*pa, 1);
		smol_sort(pa);
	}
	else if (a > b && b > c)
	{
		ra(pa, 1);
		sa(*pa, 1);
	}
	else if (a > b && b < c)
		sa(*pa, 1);
}

static void	high_five_sort(t_ps **ps_a, t_ps **ps_b)
{
	while (stack_len(*ps_a) > 3)
		push_min(ps_a, ps_b);
	smol_sort(ps_a);
	while (stack_len(*ps_b) != 0)
		pa(ps_a, ps_b);
	return ;
}

static void	chonky_sort(t_ps **ps_a, t_ps **ps_b)
{
	while (stack_len(*ps_a) != 0)
		push_min(ps_a, ps_b);
	while (stack_len(*ps_b) != 0)
		pa(ps_a, ps_b);
	return ;
}

void	choose_sort(t_ps **pa, t_ps **pb)
{
	if ((*pa)->argc <= 4)
	{
		smol_sort(pa);
		return ;
	}
	else if ((*pa)->argc > 4 && (*pa)->argc <= 6)
	{
		high_five_sort(pa, pb);
		return ;
	}
	else if ((*pa)->argc > 6)
	{
		chonky_sort(pa, pb);
		return ;
	}
	return ;
}
