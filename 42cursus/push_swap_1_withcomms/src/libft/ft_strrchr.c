/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:51:09 by ldalmass          #+#    #+#             */
/*   Updated: 2022/11/18 14:27:31 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (c >= 256)
		c = c - 256;
	while (s[i] != '\0')
		i = i + 1;
	while (i >= 0)
	{
		if (s[i] == c)
			return (((char *)&s[i]));
		i = i - 1;
	}
	if (c == '\0')
		return (((char *)&s[i]));
	return (NULL);
}
