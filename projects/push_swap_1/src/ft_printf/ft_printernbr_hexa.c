/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printernbr_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:26:31 by ldalmass          #+#    #+#             */
/*   Updated: 2023/05/24 04:12:53 by ldalmass         ###   ########.fr       */
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
		len += write(1, &base_upper[n], 1);
	else
		len += write(1, &base_lower[n], 1);
	return (len);
}

int	ft_printernbr_hexa(unsigned int n, int i, int len)
{
	unsigned int	unit;

	unit = n % 16;
	if (n < 16)
		len = base_hexa(unit, i, len);
	else
	{
		len = ft_printernbr_hexa(n / 16, i, len);
		len = base_hexa(unit, i, len);
	}
	return (len);
}
