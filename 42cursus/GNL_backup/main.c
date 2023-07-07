/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:35:51 by ldalmass          #+#    #+#             */
/*   Updated: 2023/01/12 19:48:16 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int	i;
	int	fd;
	char *str;

	i = 0;
	printf("[Buffer Size : %d]\n", BUFFER_SIZE);
//	fd = open("test.txt" , O_RDONLY);
	str = get_next_line(100);
	while (i != 2)
	{
		printf("Ligne %d --- [%s]\n", i, str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	return (0);
}
