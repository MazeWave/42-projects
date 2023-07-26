/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:41:20 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 04:52:38 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps **ps_a, t_ps **ps_b)
{
	t_ps	*first;
	t_ps	*sec;

	ft_printf("pa\n");
	if (!ps_b)
		return ;
	first = *ps_b;
	sec = (*ps_b)->next;
	*ps_b = sec;
	sec = *ps_a;
	*ps_a = first;
	(*ps_a)->next = sec;
	return ;
}
