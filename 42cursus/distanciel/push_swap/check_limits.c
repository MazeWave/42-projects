/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:12:34 by ldalmass          #+#    #+#             */
/*   Updated: 2023/07/15 03:55:27 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pos_limit(t_ps *ps, int i, int k)
{
	//ft_printf("       LIMIT (+)\n");
	while (ps->argv[i][k] == '0')
		k++;
	if (ft_strlen(ps->argv[i]) - k == 10 && ft_strncmp(ps->argv[i] + k,
			"2147483647", ft_strlen(ps->argv[i]) - k) > 0)
	{
	//	ft_printf("ERROR LIMIT (+)	: %d\n", ft_strncmp(ps->argv[i] + k, "2147483647", ft_strlen(ps->argv[i]) - k));
		return (1);
	}
	else if (ft_strlen(ps->argv[i]) - k > 10)
	{
	//	ft_printf("ERROR LIMIT (len): %d\n", ft_strlen(ps->argv[i]) - k);
		return (1);
	}
	return (0);
}

static int	neg_limit(t_ps *ps, int i, int k)
{
	//ft_printf("       LIMIT (-)\n");
	if (ps->argv[i][0] == '-')
		k++;
	while (ps->argv[i][k] == '0')
		k++;
	if (ft_atol(ps->argv[i]) < -2147483648)
	{
		//ft_printf("ERROR LIMIT (-)\n");
		return (1);
	}
	return (0);
}

int	check_limits(t_ps *ps)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (i < ps->argc)
	{
		while (ps->argv[i][j] != '\0')
		{
			if (ps->argv[i][0] == '-')
				return (neg_limit(ps, i, k));
			else
				return (pos_limit(ps, i, k));
			j++;
		}
		//ft_printf("      LIMIT len = %d\n", ft_strlen(ps->argv[i]));
		j = 0;
		i++;
	}
	return (0);
}
