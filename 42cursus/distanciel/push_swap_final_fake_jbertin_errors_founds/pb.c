/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:44:21 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 02:57:13 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_ps **ps_a, t_ps **ps_b)
{
	t_ps	*first;
	t_ps	*sec;

	if (!ps_a)
		return ;
	ft_printf("pb\n");
	first = *ps_a;
	sec = (*ps_a)->next;
	*ps_a = sec;
	sec = *ps_b;
	*ps_b = first;
	(*ps_b)->next = sec;
	return ;
}
