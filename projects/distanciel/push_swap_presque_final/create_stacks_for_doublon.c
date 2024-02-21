/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks_for_doublon.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass < ldalmass@student.42nice.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:16:06 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/02 23:16:01 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stacks_for_doublon(t_ps *ps, int i)
{
	t_ps	*new;
	t_ps	*temp;

	temp = ps;
	ps->value = ft_atoi(ps->argv[1]);
	ps->index = 0;
	ps->next = NULL;
	while (i < ps->argc)
	{
		new = malloc(sizeof(t_ps));
		if (!new || !ps)
			return ;
		new->value = ft_atoi(ps->argv[i]);
		new->index = i;
		new->next = NULL;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		i++;
	}
	return ;
}
