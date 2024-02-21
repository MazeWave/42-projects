/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:30:40 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/02 03:45:23 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_ps *ps, int p)
{
	int	temp;

	if (p == 1)
		ft_printf("sb\n");
	if (ps->next == NULL)
		return ;
	temp = ps->value;
	ps->value = ps->next->value;
	ps->next->value = temp;
	temp = ps->index;
	ps->index = ps->next->index;
	ps->next->index = temp;
	return ;
}
