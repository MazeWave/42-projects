/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:17:20 by ldalmass          #+#    #+#             */
/*   Updated: 2022/12/12 22:45:40 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

size_t	ft_stringlen(const char *s);
size_t	ft_stringcpy(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);
char	*ft_stringjoin(char *s1, char *s2);
char	*ft_stringchr(const char *s, int c);
char	*ft_read_current(int fd, char *stash, int *read_value);
char	*ft_print_and_reduce(char *stash, char **dupli, int read_value);
char	*ft_substring(char const *s, unsigned int start, size_t len);
char	*ft_print_until_newline(char *str, int read_value);
char	*ft_stringdup(const char *s1);

#endif