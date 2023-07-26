/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:22:43 by ldalmass          #+#    #+#             */
/*   Updated: 2022/11/29 16:07:55 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*cpy;
	int		index;

	i = 0;
	index = 0;
	cpy = (char *)s;
	while (i < n)
	{
		if ((unsigned char)cpy[i] == (unsigned char)c)
			return (&cpy[i]);
		i = i + 1;
	}
	return (0);
}
