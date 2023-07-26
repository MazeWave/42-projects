/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:11:58 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 03:55:05 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parser(t_ps *ps)
{
	int		parsing_error;
	t_ps	*temp;

	temp = ps;
	parsing_error = 0;
	if (ps->argc <= 2)
	{
		ft_printf("ERROR ARGC NUM\n");
		return (1);
	}
	ft_printf("Parsing error argc : %d\n", parsing_error);
	parsing_error += check_types(ps);
	ft_printf("Parsing error types : %d\n", parsing_error);
	parsing_error += check_limits(ps);
	ft_printf("Parsing error limits : %d\n", parsing_error);
	create_stacks(ps, 2);
	while (temp)
	{
		parsing_error += check_doublon(ps, temp->value, temp->index);
		temp = temp->next;
	}
	ft_printf("Parsing error doublon : %d\n", parsing_error);
	return (parsing_error);
}
