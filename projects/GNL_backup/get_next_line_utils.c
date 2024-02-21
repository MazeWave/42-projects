/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:15:46 by ldalmass          #+#    #+#             */
/*   Updated: 2023/01/10 02:02:27 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_stringlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i = i + 1;
	return (i);
}

int	ft_stringchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (c >= 256)
		c = c - 256;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);	//return l'adrr du char trouvé
		i = i + 1;
	}
	if (c == '\0')
		return (i);		//return l'adrr du '\0' trouvé
	else
		return (-1);				//return NULL si char non trouvé
}

size_t	ft_stringcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i = i + 1;
		}
		dst[i] = '\0';	//null terminate
	}
	return (ft_stringlen(src));
}

char	*ft_stringjoin(char *s1, char *s2)
{
	char		*s3;
	size_t		i;
	size_t		j;
	size_t		lenone;
	size_t		lentwo;

	lenone = ft_stringlen(s1);
	lentwo = ft_stringlen(s2);
	j = -1;
	i = lenone + lentwo;
	s3 = malloc(sizeof(char) * (i + 1));
	if (!s3)
		return (NULL);
	i = -1;
	while (++i < lenone)
		s3[i] = s1[i];
	while (++j < lentwo)
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	free(s1);
	return (s3);
}

char	*ft_stringdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_stringlen(s1);
	ptr = malloc(sizeof(*s1) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i = i + 1;
	}
	ptr[i] = 0;
	return (ptr);
}
