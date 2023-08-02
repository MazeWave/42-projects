/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:59:03 by ldalmass          #+#    #+#             */
/*   Updated: 2022/11/21 16:08:54 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_size(int n, int *is_negative)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		*is_negative = 1;
		n = n * -1;
		i = i + 1;
	}
	while (n >= 10)
	{
		n /= 10;
		i = i + 1;
	}
	if (n >= 0 && n < 10)
		i = i + 1;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		is_negative;
	int		i;

	is_negative = 0;
	i = 0;
	i = number_size(n, &is_negative);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	if (n < 0)
		n = -n;
	result[i] = '\0';
	i = i - 1;
	while (i >= 0)
	{
		result[i] = (n % 10) + '0';
		n /= 10;
		i = i - 1;
	}
	if (is_negative == 1)
		result[0] = '-';
	return (result);
}
