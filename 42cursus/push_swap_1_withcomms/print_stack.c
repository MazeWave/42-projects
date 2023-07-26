/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:25:39 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/14 23:53:56 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_ps *ps, char c)
{
	t_ps	*temp;

	temp = ps;
	ft_printf("\n%c Stack : [index] => [value]\n|\n", c);
	while (temp)
	{
		ft_printf("|        [%d] => [%d]\n", temp->index, temp->value);
		temp = temp->next;
	}
	ft_printf("----------------------------\n");
	return ;
}
