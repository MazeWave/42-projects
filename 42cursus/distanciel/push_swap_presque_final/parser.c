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
	parsing_error = check_types(ps);
	parsing_error += check_limits(ps);
	create_stacks_for_doublon(ps, 2);
	while (temp)
	{
		parsing_error += check_doublon(ps, temp->value, temp->index);
		temp = temp->next;
	}
	temp = ps;
	while (temp)
	{
		temp->index = 0;
		temp = temp->next;
	}
	return (parsing_error);
}
