/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:13:31 by ldalmass          #+#    #+#             */
/*   Updated: 2022/12/12 22:54:24 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_eol(char *stash)
{
	int	i;
	int	eol;

	i = 0;
	eol = 0;
	if (stash == NULL)
		return (0);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')	//detect '\n' whenever it's pos
			eol = 1;
		i = i + 1;
	}
	return (eol);
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
		return (NULL);	//if buffer empty or null
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i = i + 1;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_read_current(int fd, char *stash, int *read_value)
{
	char	buffer[BUFFER_SIZE + 1];

	*read_value = read(fd, buffer, BUFFER_SIZE);
	if (*read_value < 0)
		return (stash = NULL);
	if (*read_value == 0)	// Bricolage
		return (stash);
	buffer[*read_value] = '\0';
	if (stash == NULL)
		stash = ft_stringdup(buffer);
	else
		stash = ft_stringjoin(stash, buffer);	//add buffer to stash + null terminate
	return (stash);
}

char	*ft_print_and_reduce(char *stash, char **dupli, int read_value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*dupli = ft_print_until_newline(stash, read_value);	//ligne propre '\n\0' ou '\0' terminated
	while (stash[j] != '\n' && stash[j])
		j = j + 1;
	i = ft_stringlen(stash);
	i = i - j;
	stash = ft_substring(stash, j, i);	//coupe stash pour garder que après '\n' + null terminate
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*dupli;
	int			read_value;

	read_value = -1;
	dupli = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (is_eol(stash) == 0 && read_value != 0) // Bricolage read_value != 0
	{
		stash = ft_read_current(fd, stash, &read_value);
		if (stash == NULL)
			return (NULL);
	}
	if (read_value < 0)
		return (NULL);
	else if (read_value == 0)
		stash = ft_print_and_reduce(stash, &dupli, 0);
	else if (read_value > 0)
		stash = ft_print_and_reduce(stash, &dupli, 1);
	return (dupli);
}
