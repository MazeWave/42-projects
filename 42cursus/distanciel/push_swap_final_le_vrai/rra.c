/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:24:02 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/02 03:15:55 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps **ps, int p)
{
	t_ps	*val;
	t_ps	*temp;	

	if (*ps == NULL || (*ps)->next == NULL)
		return ;
	if (p == 1)
		ft_printf("rra\n");
	temp = *ps;
	while (temp->next->next)
		temp = temp->next;
	val = temp->next;
	val->next = *ps;
	*ps = val;
	temp->next = NULL;
	return ;
}
