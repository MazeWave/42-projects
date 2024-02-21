/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:34:29 by ldalmass          #+#    #+#             */
/*   Updated: 2022/12/05 20:18:35 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flags(long long args, const char *format, int *i, int len)
{
	{
		*i = *i + 1;
		if (format[*i] == 'c')
			len = ft_printerchar((char) args, len);
		if (format[*i] == 's')
			len = ft_printerstr((char *) args, len);
		if (format[*i] == 'd' || format[*i] == 'i')
			len = ft_printernbr((int) args, len);
		if (format[*i] == 'u')
			len = ft_printernbr_unsigned((unsigned int) args, len);
		if (format[*i] == 'x')
			len = ft_printernbr_hexa((unsigned int) args, 0, len);
		if (format[*i] == 'X')
			len = ft_printernbr_hexa((unsigned int) args, 1, len);
		if (format[*i] == 'p')
			len = ft_adress_hexa((unsigned long) args, len);
		if (format[*i] == '%')
			len += write(1, "%", 1);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = -1;
	va_start(args, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && ft_stringchr("cspdiuxX", format[i + 1]))
			len = flags(va_arg(args, long long), format, &i, len);
		else if (format[i] == '%' && format[i + 1] == '%')
			len = flags(1, format, &i, len);
		else
			len = ft_printerchar(format[i], len);
	}
	va_end(args);
	return (len);
}
