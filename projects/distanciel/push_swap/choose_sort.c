/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:33:21 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 04:36:49 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static int	find_max_shift(t_ps ps_a)
{
	t_ps	*temp;
	int		max;
	int		count;
	int		i;

	temp = *ps_a;
	max = 0;
	i = 32;
	count = 32;
	while (temp)
	{
		while (i > 0)
		{
			if ()
		}
		temp = temp->next;
	}
	return (max);
}*/

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
	else if (a > b && b < c && c < a)
		ra(pa, 1);
	else if (a > b && b < c && c > a)
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
	int	i;
	int	shift;
	int	base_len;

	i = 0;
	shift = 0;
	base_len = stack_len(*ps_a);

	while (check_order(*ps_a) == 1)
	{
		while (i < base_len)
		{
			if (((*ps_a)->index >> shift) & 1)
				ra(ps_a, 1);
			else
				pb(ps_a, ps_b);
			i++;
		}
		while (stack_len(*ps_b) != 0)
			pa(ps_a, ps_b);
		shift++;
		i = 0;
	}
	return ;
}

/*static void	chonky_sort(t_ps **ps_a, t_ps **ps_b)
{
	while (stack_len(*ps_a) != 0)
		push_min(ps_a, ps_b);
	while (stack_len(*ps_b) != 0)
		pa(ps_a, ps_b);
	return ;
}*/

/*
	int	base_len;
	//int	i;

	base_len = stack_len(*ps_a);

	//i = 0;
	while (stack_len(*ps_a) > base_len / 2)
	{
		if ((*ps_a)->index > base_len / 2)
			pb(ps_a, ps_b);
		else if ((*ps_a)->index > (*ps_a)->next->index)
			sa(*ps_a, 1);
		else
			ra(ps_a, 1);
	}

	ft_printf("BASE / 2 = %d\n", base_len / 2);
	while (check_order(*ps_a) == 1)
	{
		usleep(1000);
		if ((*ps_a)->index > base_len / 4)
			ra(ps_a, 1);
		else if ((*ps_a)->index > (*ps_a)->next->index)
		{
			sa(*ps_a, 1);
			system("clear");
			print_stack(*ps_a, 'A');
			usleep(1000);
		}
		else if ((*ps_a)->index == (base_len / 2) && (*ps_a)->next->index == 1)
			break ;
		else
			break ;
	}
*/

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
