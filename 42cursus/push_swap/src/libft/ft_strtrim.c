/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:31:58 by ldalmass          #+#    #+#             */
/*   Updated: 2022/11/22 19:00:11 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	l_alloc(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && s1[i])
		i = i + 1;
	return (i);
}

size_t	r_alloc(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (j != 0)
		j = j - 1;
	while (ft_strchr(set, s1[j]) != NULL && j > 0)
	{
		i = i + 1;
		j = j - 1;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	r;
	size_t	l;

	if (!set || !s1)
		return (NULL);
	r = r_alloc(s1, set);
	l = l_alloc(s1, set);
	result = ft_substr(s1, l, ft_strlen(s1) - (l + r));
	if (!result)
		return (NULL);
	return (result);
}
