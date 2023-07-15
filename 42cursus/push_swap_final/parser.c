/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:11:58 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 04:52:54 by ldalmass         ###   ########.fr       */
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
		return (1);
	parsing_error += check_types(ps);
	parsing_error += check_limits(ps);
	create_stacks(ps, 2);
	while (temp)
	{
		parsing_error += check_doublon(ps, temp->value, temp->index);
		temp = temp->next;
	}
	return (parsing_error);
}
