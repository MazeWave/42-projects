/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:05:10 by ldalmass          #+#    #+#             */
/*   Updated: 2023/03/23 12:27:40 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char *str)
{
	int		i;
	int		j;
	char	*rev;

	i = 0;
	j = 0;
	rev = ft_calloc(sizeof(char) * ft_strlen(str) + 1, 1);
	if (!rev)
		return (0);
	while (str[i] != '\0')
		i = i + 1;
	rev[i] = '\0';
	i = i - 1;
	while (i >= 0)
	{
		rev[j] = str[i];
		i = i - 1;
		j = j + 1;
	}
	return (rev);
}

/*int	main(int argc, char **argv)
{
	char	*str;

	if (argc == 2)
	{
		str = ft_calloc(sizeof(char) * ft_strlen(argv[1]), 1);
		if (!str)
			return (0);
		str = ft_reverse(argv[1]);
		ft_writer(str);
	}
	return (0);
}*/