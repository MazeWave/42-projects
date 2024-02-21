/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:18:02 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 04:43:48 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	close_swap(t_ps *ps_a)
{
	t_ps	*temp;

	temp = ps_a;
	while (temp)
		temp = temp->next;
	free (temp);
	exit(EXIT_SUCCESS);
}
