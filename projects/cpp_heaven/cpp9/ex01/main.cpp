/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2025/02/05 16:43:57 by ldalmass         ###   ########.fr       */
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
	
	RPN	Expression(argv[1]);

	// // Copy constructor test
	// RPN	test("7 7 * 7 -");
	// RPN	copy1(test);

	// // = overload operator test
	// RPN	copy2;
	// copy2 = copy1;

	// // Check result stored in copy1 and copy2
	// std::stack<double>	data = copy1.getStack();
	// std::cout << data.top() << std::endl;

	// data = copy2.getStack();
	// std::cout << data.top() << std::endl;

	return (0);
}
