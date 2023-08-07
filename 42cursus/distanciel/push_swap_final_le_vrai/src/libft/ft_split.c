/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:30:17 by ldalmass          #+#    #+#             */
/*   Updated: 2022/11/28 22:31:42 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_counter(char const *s, char c)
{
	size_t	word;
	size_t	i;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i = i + 1;
		while (s[i] != c && s[i])
			i = i + 1;
		word++;
		while (s[i] == c && s[i])
			i = i + 1;
	}
	return (word + 1);
}

char	**copieur(char const *s, char c, char **result)
{
	size_t	word;
	size_t	i;
	size_t	j;

	word = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i = i + 1;
		j = i;
		while (s[i] != c && s[i])
			i = i + 1;
		result[word] = malloc(sizeof(char) * (i - j + 1));
		ft_strlcpy(result[word], &(s[j]), i - j + 1);
		if (!result[word])
			return (NULL);
		word = word + 1;
		while (s[i] == c && s[i])
			i = i + 1;
	}
	result[word] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * word_counter(s, c));
	if (!result)
		return (NULL);
	while (s[j] != '\0')
	{
		while (s[i] == c)
			i = i + 1;
		j = j + 1;
	}
	if (i == (unsigned int)ft_strlen(s))
	{
		result[0] = NULL;
		return (result);
	}
	result = copieur(s, c, result);
	return (result);
}
