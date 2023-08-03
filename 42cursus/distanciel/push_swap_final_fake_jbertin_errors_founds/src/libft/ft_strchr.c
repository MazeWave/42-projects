/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:29:08 by ldalmass          #+#    #+#             */
/*   Updated: 2022/11/29 16:08:38 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (c >= 256)
		c = c - 256;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i = i + 1;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}
