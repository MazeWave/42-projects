/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:16:06 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/22 22:35:40 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stacks(t_ps *ps, int i)
{
	t_ps	*new;
	t_ps	*temp;

	temp = ps;
	ps->value = ft_atoi(ps->argv[1]);
	ps->index = 0;
	while (i < ps->argc)
	{
		new = malloc(sizeof(t_ps));
		if (!new || !ps)
			return ;
		new->value = ft_atoi(ps->argv[i]);
		new->index = i - 1;
		new->next = NULL;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		i++;
	}
	return ;
}
