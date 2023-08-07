/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:51:37 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/02 03:44:48 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps, int p)
{
	int	temp;

	if (ps->next == NULL)
		return ;
	if (p == 1)
		ft_printf("sa\n");
	temp = ps->value;
	ps->value = ps->next->value;
	ps->next->value = temp;
	temp = ps->index;
	ps->index = ps->next->index;
	ps->next->index = temp;
	return ;
}
