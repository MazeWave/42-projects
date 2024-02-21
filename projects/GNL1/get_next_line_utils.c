/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:15:46 by ldalmass          #+#    #+#             */
/*   Updated: 2022/12/12 23:06:37 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_stringlen(const char *s)
{
	if (s[0] != '\0')
		return (ft_stringlen(s + 1) + 1);
	return (0);
}

char	*ft_stringjoin(char *s1, char *s2)
{
	char		*s3;
	size_t		i;
	size_t		j;

	j = -1;
	i = ft_stringlen(s1) + ft_stringlen(s2);
	s3 = malloc(sizeof(char) * (i + 1));
	if (!s3)
		return (NULL);
	i = -1;
	while (++i < ft_stringlen(s1))	//copy s1 in s3
		s3[i] = s1[i];
	while (++j < ft_stringlen(s2))	//append s2 onto s3
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	free(s1);
	//no need to free s2 (buffer) because no malloc ont it.
	return (s3);
}

char	*ft_print_until_newline(char *stash, int read_value)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] != '\n' && stash[i])	//count until \n or \0
		i = i + 1;
	line = malloc(sizeof(char) * (i + 1 + read_value));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])	//copy until \n or \0 if no \n
	{
		line[i] = stash[i];
		i = i + 1;
	}
	if (read_value == 1)
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else if (read_value == 0)
		line[i] = '\0';
	return (line);
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
		dst[i] = '\0';
	}
	return (ft_stringlen(src));
}

char	*ft_substring(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (ft_stringlen(s) <= start)
		len = 0;
	if (len > ft_stringlen(s) - start)
		len = ft_stringlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (len <= 0)
		return (str);
	ft_stringcpy(str, &s[start], len + 1);	// A QUOI IL SERT SUS
	//free((char *)s);
	return (str);
}
