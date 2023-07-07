/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:13:31 by ldalmass          #+#    #+#             */
/*   Updated: 2023/01/10 02:38:19 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_current(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];	//+1 to null terminate
	int 	read_value;

	read_value = read(fd, buffer, BUFFER_SIZE);
	if (read_value < 0)
		return (NULL);
	buffer[read_value] = '\0';
	if (!stash)
		stash = ft_stringdup(buffer);
	else
		stash = ft_stringjoin(stash, buffer);	
	while (read_value > 0)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		buffer[read_value] = '\0';
		stash = ft_stringjoin(stash, buffer);
		//printf("-_-HERE-_-\n");
	}
	return (stash);
}

char	*ft_reduce_line(char **stash, char *dupli)
{
	size_t	i;

	i = 0;
	while (((*stash)[i] != '\n') && ((*stash)[i] != '\0'))	//	compte jusqu'à '\n' OU '\0'
		i = i + 1;
	
	if (ft_stringchr(*stash, '\n') != -1)
		i++;
	dupli = malloc(sizeof(char) * (i + 1));
	ft_stringcpy(dupli, *stash, i + 1);
	/* RESTE */
	//printf("i = %zu,\tlen = %zu\n", i, ft_stringlen(*stash));
	if (i == ft_stringlen(*stash))
	{
		*stash = NULL;
	}
	else if (ft_stringchr(*stash, '\0') != 0)
		ft_stringcpy(*stash, &((*stash)[i]), (i - ft_stringlen(*stash)));	//	stash = le reste + null terminate
	else
		free(*stash);
	//printf("Stash : [%s]\n", *stash);
	//printf("Dupli : [%s]\n", dupli);
	return(dupli);
}

char	*get_next_line(int fd)	// FONCTION CORRECTE
{
	static char	*stash;
	char		*dupli;

	dupli = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)	//empty text or no buffer
		return (NULL);
	stash = ft_read_current(fd, stash);	//ligne non propre, reste a nettoyer
	if (stash == NULL)
		return (NULL);
	dupli = ft_reduce_line(&stash, dupli);	//dupli = ligne propre prete a etre renvoyé. stash = suite de la ligne NULL terminated
	return (dupli);
}
