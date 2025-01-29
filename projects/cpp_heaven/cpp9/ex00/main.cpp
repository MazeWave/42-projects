/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2025/01/28 22:10:20 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int	print_usage(void)
{
	std::cout << RED << "./btc [path to file]" << RESET << std::endl;
	exit (-1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		print_usage();
	
	try {BitcoinExchange	wallet(argv[1]);}
	catch (std::exception	&error) {std::cout << error.what() << std::endl;return (-1);}

	return (0);
}
