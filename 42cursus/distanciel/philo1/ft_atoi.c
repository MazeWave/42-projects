/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:21:45 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/22 16:57:11 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	ft_atoi(const char *str)
{
	unsigned int	number;
	unsigned int	sign;
	unsigned int	i;

	number = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i = i + 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i = i + 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i = i + 1;
	}
	return (number * sign);
}
