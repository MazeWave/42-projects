/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 03:16:55 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/02 03:17:20 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_ps **ps, int p)
{
	t_ps	*val;
	t_ps	*temp;	

	if (*ps == NULL || (*ps)->next == NULL)
		return ;
	if (p == 1)
		ft_printf("rrb\n");
	temp = *ps;
	while (temp->next->next)
		temp = temp->next;
	val = temp->next;
	val->next = *ps;
	*ps = val;
	temp->next = NULL;
	return ;
}
