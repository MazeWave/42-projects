/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:20:55 by ldalmass          #+#    #+#             */
/*   Updated: 2022/12/01 23:32:08 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	base(unsigned long n, int len)
{
	char	*base;

	base = "0123456789abcdef";
	len += write(1, &base[n], 1);
	return (len);
}

static int	ft_addr_to_hexa(unsigned long n, int len)
{
	unsigned long	unit;

	unit = n % 16;
	if (n < 16)
		len = base(unit, len);
	else
	{
		len = ft_addr_to_hexa(n / 16, len);
		len = base(unit, len);
	}
	return (len);
}

int	ft_adress_hexa(unsigned long n, int len)
{
	len += write(1, "0x", 2);
	len = ft_addr_to_hexa(n, len);
	return (len);
}
