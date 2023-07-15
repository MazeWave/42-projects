/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:54:38 by ldalmass          #+#    #+#             */
/*   Updated: 2022/11/29 16:08:18 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*g;
	size_t			i;

	i = 0;
	g = b;
	while (i < len)
	{
		g[i] = (unsigned char)c;
		i = i + 1;
	}
	return (g);
}
