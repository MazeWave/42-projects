/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printernbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:12:45 by ldalmass          #+#    #+#             */
/*   Updated: 2023/06/27 17:58:37 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <limits.h>

int	ft_count_numbers(int n, int len)
{
	if (n == -2147483648)
		return (len += 11);
	else if (n < 0)
	{
		n = -n;
		len = ft_count_numbers(n, len += 1);
	}
	else if (n < 10)
		return (len += 1);
	else
		len = ft_count_numbers(n / 10, len += 1);
	return (len);
}

static void	ft_theprinternbr(int n)
{
	char	unit;

	unit = n % 10 + '0';
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_theprinternbr(n);
	}
	else if (n < 10)
		write(1, &unit, 1);
	else
	{
		ft_theprinternbr((n / 10));
		write(1, &unit, 1);
	}
}

int	ft_printernbr(int n, int len)
{
	ft_theprinternbr(n);
	return (ft_count_numbers(n, len));
}

// int	main(int argc, char **argv)
// {
// 	printf("%d\n", INT_MIN);
// 	ft_printernbr(atoi(argv[1]), 0);
// 	printf("\nlen = %d\n", ft_count_numbers(atoi(argv[1]), 0));
// 	ft_printernbr(INT_MIN, 0);
// 	ft_printf("\nlen = %d\n", ft_count_numbers(INT_MIN, 0));
// 	ft_printf("%z %s", INT_MIN, "tom le bg");
// 	return (0);
// }
