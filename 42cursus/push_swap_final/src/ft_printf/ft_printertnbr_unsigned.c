/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printertnbr_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:32:41 by ldalmass          #+#    #+#             */
/*   Updated: 2022/12/01 23:32:57 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printernbr_unsigned(unsigned int n, int len)
{
	char	unit;

	unit = n % 10 + 48;
	if (n < 10)
		len += write(1, &unit, 1);
	else
	{
		len = ft_printernbr_unsigned((n / 10), len);
		len += write(1, &unit, 1);
	}
	return (len);
}
