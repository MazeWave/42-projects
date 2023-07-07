/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:44:21 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/01 22:54:02 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_ps **ps_a, t_ps **ps_b)
{
	t_ps	*first;
	t_ps	*sec;

	ft_printf("pb\n");
	if (!ps_a)
		return ;
	first = *ps_a;			//save top b
	sec = (*ps_a)->next;	//save next b
	*ps_a = sec;			//new top b is next b

	sec = *ps_b;			//save top a
	*ps_b = first;			//point top a to old top b
	(*ps_b)->next = sec;	//old top a is next a

	return ;
}
