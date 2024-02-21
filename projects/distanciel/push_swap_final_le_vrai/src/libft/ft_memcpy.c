/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:54:56 by ldalmass          #+#    #+#             */
/*   Updated: 2022/11/29 16:08:09 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cpy;
	unsigned char	*dest;

	i = 0;
	cpy = (unsigned char *) src;
	dest = (unsigned char *) dst;
	if (!dest && !cpy)
		return (NULL);
	while (i < n)
	{
		dest[i] = cpy[i];
		i = i + 1;
	}
	return (dst);
}
