/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:26:31 by ldalmass          #+#    #+#             */
/*   Updated: 2022/12/01 15:36:32 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	base_hexa(unsigned int n, int i, int len)
{
	char	*base_lower;
	char	*base_upper;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (i == 1)
	{
		write(1, &base_upper[n], 1);
		len += 1;
	}
	else
	{
		write(1, &base_lower[n], 1);
		len += 1;
	}
	return (len);
}

int	ft_putnbr_hexa(unsigned int n, int i, int len)
{
	unsigned int	unit;

	unit = n % 16;
	if (n < 16)
		base_hexa(unit, i, len);
	else
	{
		ft_putnbr_hexa(n / 16, i, len);
		base_hexa(unit, i, len);
	}
	return (len);
}
