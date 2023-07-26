/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:05:46 by ldalmass          #+#    #+#             */
/*   Updated: 2022/11/29 16:09:05 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *pattern, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*pattern == '\0')
		return ((char *)str);
	if (!str && !len)
		return (0);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] && (str[i + j] == pattern[j]) && (i + j < len))
		{
			j = j + 1;
			if (pattern[j] == '\0')
				return ((char *)str + i);
		}
		i = i + 1;
	}
	return (0);
}
