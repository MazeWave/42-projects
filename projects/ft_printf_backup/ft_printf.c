/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:34:29 by ldalmass          #+#    #+#             */
/*   Updated: 2022/12/01 16:27:42 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	advanced_flags(va_list args, const char *format, int i, int len)
{
	{
		if (format[i + 1] == 'c')
			len += ft_putchar(args, len);
		if (format[i + 1] == 's')
			len += ft_putstr(args, len);
		if (format[i + 1] == 'd' || format[i + 1] == 'i')
			len += ft_putnbr(args, len);
		if (format[i + 1] == 'u')
			len += ft_putnbr_unsigned(args, len);
		if (format[i + 1] == '%')
		{
			write(1, '%', 1);
			len += 1;
		}
		if (format[i + 1] == 'x')
			len += ft_putnbr_hexa(args, 0, len);
		if (format[i + 1] == 'X')
			len += ft_putnbr_hexa(args, 1, len);
		if (format[i + 1] == 'p')
			len += ft_adress_hexa(args, len);
	}
	return (len);
}

static int	flags(va_list args, const char *format, int len)
{
	int			i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			advanced_flags(args, format, i, len);
		ft_putchar(args, len);
		i = i + 1;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;

	va_start(args, format);
	while (va_arg(args, type) != NULL)
	{
		flags(args, format, len);
	}
	va_end(args);
	return (len);
}
