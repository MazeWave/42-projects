/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:56:14 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/27 19:26:04 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doublon(t_ps *ps, int value, int index)
{
	t_ps	*temp;

	temp = ps;
	while (temp->next)
	{
		if (temp->value == value && temp->index < index)
		{
			ft_printf("ERROR DOUBLON	: %d == %d\n", temp->value, value);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}
