/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:52:12 by ldalmass          #+#    #+#             */
/*   Updated: 2023/09/24 18:55:40 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *str)
{
	if (str[0] != '\0')
		return (ft_strlen(str + 1) + 1);
	return (0);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i = i + 1;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

int	ft_strncmp(const char *s1, const char *s2, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
			i = i + 1;
		else
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
	}
	return (0);
}

char	*ft_truncate(char *str)
{
	char	*result;
	int		result_len;
	int		neg;

	neg = 0;
	if (str == NULL)
		return (NULL);
	if (str[0] == '-')
	{
		str++;
		neg++;
	}
	if (str[0] == '+')
		str++;
	while (*str == '0')
		str++;
	result_len = ft_strlen(str) + 1 + neg;
	result = malloc(sizeof(char) * result_len);
	if (result == NULL)
		return (NULL);
	if (neg == 1)
		result[0] = '-';
	ft_strlcpy(result + neg, str, result_len);
	return (result);
}

int	ft_atoi(const char *str)
{
	int	number;
	int	sign;
	int	i;

	number = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i = i + 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i = i + 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i = i + 1;
	}
	return (number * sign);
}
