/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:41:20 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/01 22:42:42 by ldalmass         ###   ########.fr       */
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
	first = *ps_b;			//save top b
	sec = (*ps_b)->next;	//save next b
	*ps_b = sec;			//new top b is next b

	sec = *ps_a;			//save top a
	*ps_a = first;			//point top a to old top b
	(*ps_a)->next = sec;	//old top a is next a

	return ;
}
