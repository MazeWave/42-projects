/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:33:21 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/11 19:07:16 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smol_sort(t_ps *pa)
{
	if (pa->value < pa->next->value && pa->next->value < pa->next->next->value)			//Ex : 1<2<3
		return ;	//123
	else if (pa->value < pa->next->value && pa->next->value > pa->next->next->value)	//Ex : 1<3>2
	{
		sa(pa, 1);	//312
		ra(pa, 1);	//123
		return ;
	}
	else if (pa->value > pa->next->value && pa->next->value > pa->next->next->value)	//Ex : 3>2>1
	{
		sa(pa, 1);	//123
		return ;
	}
	else if (pa->value > pa->next->value && pa->next->value < pa->next->next->value)	//Ex : 2>1<3
	{
		sa(pa, 1);	//123
		return ;
	}
	return ;
}

void	sort(t_ps *pa, t_ps *pb)
{
	if (pa->argc <= 4)
	{
		smol_sort(pa);
		return ;
	}
	else if (pa->argc > 4 && pa->argc <= 11)
	{
		med_sort(pa, pb);
		return ;
	}
	else if (pa->argc > 11)
	{
		chonky_sort(pa, pb);
		return ;
	}
	return ;
}
