/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:38:32 by ldalmass          #+#    #+#             */
/*   Updated: 2023/05/03 00:49:05 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char		*s3;
	size_t		i;
	size_t		j;

	i = 0;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	i = i + ft_strlen((char *)s1);
	i = i + ft_strlen((char *)s2);
	s3 = malloc(sizeof(char) * (i + 1));
	if (!s3)
		return (NULL);
	i = -1;
	while (++i < ft_strlen((char *)s1))
		s3[i] = s1[i];
	while (++j < ft_strlen((char *)s2))
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	free(s1);
	return (s3);
}
