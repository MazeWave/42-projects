/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:33:21 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/11 18:57:30 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smol_sort(t_ps pa)
{
	if (pa->value < pa->next->value && pa->next->value < pa->next->next->value)			//Ex : 123
		return ;	//123
	else if (pa->value < pa->next->value && pa->next->value > pa->next->next->value)	//Ex : 132
	{
		ra(pa, 1);	//321
		sa(pa, 1);	//231
		rra(pa, 1);	//123
		return ;
	}
	else if (pa->value > pa->next->value && pa->next->value > pa->next->next->value)	//Ex : 321
	{
		ra(pa, 1);	//213
		sa(pa, 1);	//123
		return ;
	}
	else if (pa->value > pa->next->value && pa->next->value < pa->next->next->value)	//Ex : 213
	{
		sa(pa, 1);	//123
		return ;
	}
	return ;
}

void	sort(t_ps pa, t_ps pb)
{
	if (pa->argc <= 4)
		smol_sort(pa);
	else if (pa->argc > 4 && pa->argc <= 11)
		med_sort(pa, pb);
	else if (pa->argc > 11)
		chonky_sort(pa, pb);
	return ;
}
