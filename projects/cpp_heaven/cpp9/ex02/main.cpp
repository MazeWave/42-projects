/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2025/02/07 20:03:43 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int	print_usage(void)
{
	std::cout << "Example : ./PmergeMe \"caca\"" << std::endl;
	exit (-1);
}

static bool	parse_argv(char *argv)
{
	// Number too high error
	if (std::string(argv).size() > 10)
	{
		std::cout << RED << "Input number is too high !" << RESET << std::endl;
		return (false);
	}

	// Empty error
	if (std::string(argv).empty())
	{
		std::cout << RED << "Input number is empty !" << RESET << std::endl;
		return (false);
	}
	
	// Negative number error
	if (std::strtol(argv, 0, 10) < 0)
	{
		std::cout << RED << "Input number is negative !" << RESET << std::endl;
		return (false);
	}

	// 000000000 false positive check
	char	*str = argv;
	while (*str == '0')
		++str;
	if (*str == '\0')
		return (true);

	// Not a valid number error
	if (std::strtol(str, 0, 10) == 0 && strcmp(str, "0") != 0)
	{
		std::cout << RED << "Input is not a valid number !" << RESET << std::endl;
		return (false);
	}

	return (true);
}

int		main(int argc, char **argv)
{
	std::string inputs = "Input numbers : [";
	std::string	output;

	if (argc < 2)
		print_usage();

	std::cout << MAGENTA << "---------------------------------------------------------------------------------" << RESET << std::endl;

	for (unsigned short i = 1; i < argc; i++)
	{
		// Check input validity
		if (parse_argv(argv[i]) == false)
			return (1);

		// Create our input string for comparaisons
		inputs += argv[i];
		(i + 1 != argc) ? inputs += ", " : inputs += "]";
	}

	// std::cout << inputs << std::endl;

	PmergeMe	Sorting(argc, argv);

	std::cout << MAGENTA << "---------------------------------------------------------------------------------" << RESET << std::endl;
	return (0);
}
