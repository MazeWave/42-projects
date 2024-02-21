/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_neighbor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass < ldalmass@student.42nice.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:16:06 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/30 15:26:59 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nearest_max_neighbor(t_ps *ps, int index)
{
	t_ps	*temp;
	int		i;

	i = 0;
	temp = ps;
	while (temp)
	{
		if (temp->index == index + 1)
			return (i);
		temp = temp->next;
		i++;
	}
	return (-1);
}

int	nearest_min_neighbor(t_ps *ps, int index)
{
	t_ps	*temp;
	int		i;

	i = 0;
	temp = ps;
	while (temp)
	{
		if (temp->index == index - 1)
			return (i);
		temp = temp->next;
		i++;
	}
	return (-1);
}
