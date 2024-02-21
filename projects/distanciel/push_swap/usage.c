/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:03:32 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/14 22:48:09 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	usage(void)
{
	ft_printf("Usage : ./push_swap");
	ft_printf(" [int 1] [int 2] [int 3] [int 4] [int 5] ...\n\n");
	ft_printf("Don't use different types or quotes\n");
	ft_printf("Wrong : ./push_swap ");
	ft_printf("\"[int 1] [int 2] [int 3] [int 4] [int 5] ...\"\n");
	ft_printf("Wrong : ./push_swap ");
	ft_printf("[char 1] [long 2] [float 3] [double 4] [int 5] ...\n");
	return ;
}
