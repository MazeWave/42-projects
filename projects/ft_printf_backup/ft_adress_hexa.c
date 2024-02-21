/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:20:55 by ldalmass          #+#    #+#             */
/*   Updated: 2022/12/01 15:39:17 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	base(unsigned long n, int len)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, &base[n], 1);
	len += 1;
	return (len);
}

void	ft_addr_to_hexa(unsigned int n, int len)
{
	unsigned long	unit;

	unit = n % 16;
	if (n < 16)
		base(unit, len);
	else
	{
		ft_addr_to_hexa(n / 16, len);
		base(unit, len);
	}
	return (len);
}

int	ft_adress_hexa(va_list args, int len)
{
	ft_addr_to_hexa(&args, len);
	return (len);
}
