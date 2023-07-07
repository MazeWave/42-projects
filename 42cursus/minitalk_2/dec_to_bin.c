/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:07:11 by ldalmass          #+#    #+#             */
/*   Updated: 2023/03/23 17:52:04 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*convert(char *str)
{
	char	**result;
	int		str_len;
	int		i;
	int		j;

	i = 0;
	str_len = 0;
	while (str)
		str_len = str_len + 1;
	result = malloc(sizeof(char) * str_len + 1);
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 7)
		{
			if (str[i] & (1 << j))
			{
				write(1, "1", 1);
				result[i][j] = '1';
			}
			else
			{
				write(1, "0", 1);
				result[i][j] = '0';
			}
			j = j + 1;
		}
		write(1, " ", 1);
		result[i] = malloc(sizeof(char) * 8);
		i = i + 1;
	}
	return (*result);
}

int	main(int argc, char **argv)
{
	char	*bin;

	if (argc == 2)
	{
		bin = convert(argv[1]);
		printf("%s en binaire donne : %s", argv[1], bin);
	}
	return (0);
}
