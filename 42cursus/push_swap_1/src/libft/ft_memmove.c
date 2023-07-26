/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:16:43 by ldalmass          #+#    #+#             */
/*   Updated: 2022/11/21 17:22:14 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cpy;
	unsigned char	*dest;

	i = -1;
	cpy = (unsigned char *) src;
	dest = (unsigned char *) dst;
	if (!cpy && !dest)
		return (NULL);
	if (dest < cpy)
	{
		while (++i < n)
			*(dest++) = *(cpy++);
	}
	else if (dest > cpy)
	{
		dest = &dest[n - 1];
		cpy = &cpy[n - 1];
		while (++i < n)
			*(dest--) = *(cpy--);
	}
	return (dst);
}
