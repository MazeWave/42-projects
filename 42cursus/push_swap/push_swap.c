/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:59:38 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/14 23:56:05 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	print_stack(ps_a, 'A');
	ft_printf("////////// Parsing error : %d\n", parsing_error);
	if (parsing_error == 0)
		sort(&ps_a, &ps_b);
	else
		usage();
	print_stack(ps_a, 'A');
	ft_printf("Stack len = %d\n", stack_len(ps_a));
	close_swap(ps_a);
	return (0);
}
