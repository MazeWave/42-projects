/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 00:35:37 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/02 01:16:10 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_ps **ps, int p)
{
	t_ps	*val;
	t_ps	*temp;

	if (*ps == NULL || (*ps)->next == NULL)
		return ;
	if (p == 1)
		ft_printf("rb\n");
	val = *ps;
	*ps = (*ps)->next;
	temp = *ps;
	while (temp->next)
		temp = temp->next;
	temp->next = val;
	val->next = NULL;
	return ;
}
