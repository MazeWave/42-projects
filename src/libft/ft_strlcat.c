/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:56:53 by ldalmass          #+#    #+#             */
/*   Updated: 2022/11/29 16:08:50 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	len2(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	if (!dst && !dstsize)
		return (0);
	i = 0;
	lendst = 0;
	lensrc = len2(src);
	while (dst[lendst] && lendst < dstsize)
		lendst = lendst + 1;
	if (dstsize == 0)
		return (lensrc);
	if (lendst == dstsize && dst[i] != '\0')
		return (dstsize + lensrc);
	while ((i < dstsize - lendst - 1) && (src[i] != '\0'))
	{
		dst[i + lendst] = src[i];
		i = i + 1;
	}
	dst[i + lendst] = '\0';
	return (lendst + lensrc);
}
