/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:07:01 by ldalmass          #+#    #+#             */
/*   Updated: 2023/03/13 19:26:17 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_bin(unsigned int n, int len)
{
	char	*base;

	base = "01";
	len += base[n];
	return (len);
}

int	ft_bin(unsigned int n, int len)
{
	unsigned int	unit;

	unit = n % 2;
	if (n < 2)
		len = base_bin(unit, len);
	else
	{
		len = ft_bin(n / 2, len);
		len = base_bin(unit, len);
	}
	return (len);
}

/* int	main(int argc, char **argv)
{
	char	*bin;

	bin = ft_calloc(7, 1);
	if (!bin)
		return (0);
	if (argc == 2)
		bin = ft_itoa(ft_bin(atoi(argv[1]), 0));
	return (0);
} */
