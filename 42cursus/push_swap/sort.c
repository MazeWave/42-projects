/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:33:21 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/14 23:36:58 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smol_sort(t_ps **pa)
{
	int	a;
	int	b;
	int	c;

	a = (*pa)->value;
	b = (*pa)->next->value;
	c = (*pa)->next->next->value;
	if (a < b && b < c)			//Ex : 1<2<3
		return ;	//123
	else if (a < b && b > c)	//Ex : 1<3>2
	{
		sa(*pa, 1);	//312
		ra(pa, 1);	//123
	}
	else if (a > b && b > c)	//Ex : 3>2>1
	{
		ra(pa, 1);	//213
		print_stack(*pa, 'A');
		sa(*pa, 1);	//123
		print_stack(*pa, 'A');
	}
	else if (a > b && b < c)	//Ex : 2>1<3
		sa(*pa, 1);	//123
}

void	sort(t_ps **pa, t_ps **pb)
{
	if ((*pa)->argc <= 4)
	{
		smol_sort(pa);
		return ;
	}
	if (!(*pb))
		return ;
	/*else if ((*pa)->argc > 4 && pa->argc <= 11)
	{
		med_sort(pa, pb);
		return ;
	}
	else if ((*pa)->argc > 11)
	{
		chonky_sort(pa, pb);
		return ;
	}*/
	return ;
}
