/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:07:01 by ldalmass          #+#    #+#             */
/*   Updated: 2023/04/05 15:27:36 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dec_to_bin(unsigned int n)
{
	char	*bin;
	int		i;
	int		j;

	i = 0;
	j = 7;
	bin = malloc(sizeof (char) * 8);
	if (!bin)
		return (NULL);
	while (i <= 8)
	{
		if (n & (1 << j))
			bin[i] = '1';
		else
			bin[i] = '0';
		i = i + 1;
		j = j - 1;
	}
	return (bin);
}

/*int	main(int argc, char **argv)
{
	char	*str;
	char	*test = "Hello";

	if (argc == 2)
		ft_bin(atoi(argv[1]));
	ft_reverse(test);
	ft_writer(test);
	ft_writer(str);
	return (0);
}*/
