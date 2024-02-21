/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:29:24 by ldalmass          #+#    #+#             */
/*   Updated: 2023/03/06 22:06:51 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <wchar.h>
#include <locale.h>

void	ascii(char *str)
{
	char	c;
	int		n;
	int		i;

	c = '\0';
	n = 0;
	i = 0;
	printf("Ascii :\n");
	while (str[i] != '\0')
	{
		c = str[i];
		n = (int)(c);
		printf("%c = %d\n", c, n);
		i = i + 1;
	}
}

void	unicode(char *str)
{
	char	c;
	int		n;
	int		i;

	c = '\0';
	n = 0;
	i = 0;
	printf("Unicode :\n");
	while (str[i] != '\0')
	{
		c = str[i];
		n = (int)(c);
		printf("%c = %d\n", c, n);
		i = i + 1;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ascii(argv[1]);
		unicode(argv[1]);
	}
	return (0);
}
