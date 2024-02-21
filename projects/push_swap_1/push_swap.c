/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:59:38 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 04:53:36 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_order(t_ps *ps)
{
	t_ps	*temp;
	int		min;

	temp = ps;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
			return (1);
		min = temp->value;
		temp = temp->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_ps	push_swap_a;
	t_ps	push_swap_b;
	t_ps	*ps_a;
	t_ps	*ps_b;
	int		parsing_error;

	ps_a = &push_swap_a;
	ps_b = &push_swap_b;
	ps_b = NULL;
	ps_a->argv = argv;
	ps_a->argc = argc;
	parsing_error = 0;
	parsing_error += parser(ps_a);
	if (parsing_error == 0)
	{
		if (check_order(ps_a) == 1)
			choose_sort(&ps_a, &ps_b);
	}
	else
		usage();
	close_swap(ps_a);
	return (0);
}
