/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:21:52 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/18 21:32:21 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	fnorm(const char *str, float val, int afterdot)
{
	float	scale;

	scale = 1;
	while (*str)
	{
		if (afterdot)
		{
			scale = scale / 10;
			val = val + (*str - '0') * scale;
		}
		else
		{
			if (*str == '.')
				afterdot++;
			else
				val = val * 10.0 + (*str - '0');
		}
		str++;
	}
	return (val);
}

double	ft_atod(const char *str)
{
	float	val;
	int		afterdot;
	int		neg;

	val = 0;
	neg = 0;
	afterdot = 0;
	if (*str == '-')
	{
		str++;
		neg = 1;
	}
	val = fnorm(str, val, afterdot);
	if (neg)
		return (-val);
	else
		return (val);
}

/*double	ft_atod(const char *str, float val, int afterdot, int neg)
{
	if (*str == '-')
	{
		str++;
		neg = 1;
	}
	while (*str)
	{
		if (afterdot)
		{
			scale = scale / 10;
			val = val + (*str - '0') * scale;
		}
		else
		{
			if (*str == '.')
				afterdot++;
			else
				val = val * 10.0 + (*str - '0');
		}
		str++;
	}
	if (neg)
		return (-val);
	else
		return (val);
}*/