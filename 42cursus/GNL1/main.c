/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:35:51 by ldalmass          #+#    #+#             */
/*   Updated: 2022/12/14 16:41:05 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int fd)
{
	printf("1");printf("%s\n",get_next_line(fd));
	printf("2");printf("%s\n",get_next_line(fd));
	printf("3");printf("%s\n",get_next_line(fd));
	printf("4");printf("%s\n",get_next_line(fd));

	return (0);
}
