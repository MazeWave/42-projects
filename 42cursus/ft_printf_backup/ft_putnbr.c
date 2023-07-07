/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:12:45 by ldalmass          #+#    #+#             */
/*   Updated: 2022/12/01 15:57:38 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_negazione(int n, int len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		len += 11;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		len += 1;
		n = -n;
		ft_putnbr(n, len);
	}
	return (len);
}

int	ft_putnbr(int n, int len)
{
	char	unit;

	unit = n % 10 + 48;
	ft_negazione(n, len);
	if (n < 10)
	{
		write(1, &unit, 1);
		len += 1;
	}
	else
	{
		ft_putnbr((n / 10), len);
		write(1, &unit, 1);
		len += 1;
	}
	return (len);
}
