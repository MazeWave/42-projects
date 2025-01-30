/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2025/01/30 16:22:00 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static int	print_usage(void)
{
	std::cout << "Example : ./RPN \"1 2 * 2 / 2 * 2 4 - +\"" << std::endl;
	std::cout << RED << "./RPN \"[Reverse Polish Expression]\"" << RESET << std::endl;
	exit (-1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		print_usage();
	
	(void)argv;
	(void)argc;

	RPN	Expression(argv[1]);

	return (0);
}
