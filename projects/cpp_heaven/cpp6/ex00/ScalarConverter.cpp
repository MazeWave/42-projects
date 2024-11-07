/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:18:40 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/07 00:35:04 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::printConverted(char c, int i, float f, double d)
{
	// char display
	if (!c && c != 0)
		std::cout << YELLOW << "Char\t: Impossible" << RESET << std::endl;
	else if (!isprint(c))
		std::cout << YELLOW << "Char\t: Not displayable" << RESET << std::endl;
	else
		std::cout << YELLOW << "Char\t: " << c << RESET << std::endl;
	
	// int display
	std::cout << RED << "Int\t: " << i << RESET << std::endl;
	std::cout << GREEN << "Float\t: " << f << "f" << RESET << std::endl;
	std::cout << BLUE << "Double\t: " << d << RESET << std::endl;
	return ;
}

void	ScalarConverter::printPseudoLitterals(double d)
{
	std::cout << YELLOW << "Char\t: Impossible" << RESET << std::endl;
	std::cout << RED << "Int\t: Impossible" << RESET << std::endl;
	std::cout << GREEN << "Float\t: " << static_cast<float>(d) << "f" << RESET << std::endl;
	std::cout << BLUE << "Double\t: " << static_cast<double>(d) << RESET << std::endl;
	return ;
}

void	ScalarConverter::convertDouble(std::string str)
{
	// Debug
	if (DEBUG != 0)
		std::cout << "(float / double)" << RESET << std::endl;

	double	d = atof(str.c_str());
	printConverted
	(
		static_cast<char>(d),
		static_cast<int>(d),
		static_cast<float>(d),
		d
	);
	return ;
}

void	ScalarConverter::convertInt(std::string str)
{
	// Debug
	if (DEBUG != 0)
		std::cout << "(int)" << RESET << std::endl;

	int	i = atoi(str.c_str());
	// Checks int Overflow
	if (str.compare("2147483647") > 0 && str.length() == 10)
	{
		printPseudoLitterals(0);
		return ;
	}
	// Checks int Underflow
	else if (str.compare("-2147483648") > 0 && str.length() == 11)
	{
		printPseudoLitterals(0);
		return ;
	}
	// Checks int Overflow / Underflow edgecases
	else if ((str.length() > 11 && (str[0] == '-' || str[0] == '+')) || (str.length() > 10 && isdigit(str[0])))
	{
		printPseudoLitterals(0);
		return ;
	}
	printConverted
	(
		static_cast<char>(i),
		i,
		static_cast<float>(i),
		static_cast<double>(i)
	);
	return ;
}

void	ScalarConverter::convertChar(std::string str)
{
	// Debug
	if (DEBUG != 0)
		std::cout << "(char)" << RESET << std::endl;

	printConverted
	(
		(char)str[0],
		static_cast<int>(str[0]),
		static_cast<float>(str[0]),
		static_cast<double>(str[0])
	);
	return ;
}

void	ScalarConverter::detect(std::string str)
{
	// Debug
	if (DEBUG != 0)
		std::cout << std::endl << WHITE << "input\t: " << str << std::endl<< "type\t: " << RESET;

	short	index = -1;
	int		point = std::count(str.begin(), str.end(), '.');
	std::string	pseudo_litterals[8] = 
	{
		"nanf",
		"inff",
		"+inff",
		"-inff",
		"inf",
		"+inf",
		"-inf",
		"nan"
	};

	// Pseudo litterals detection
	for (unsigned short i = 0; i < 8; i++)
	{
		if (str == pseudo_litterals[i])
		{
			index = i;
			break;
		}
	}

	switch (point)
	{
		case 0:
			// Char detection
			if (str.length() == 0 || str.empty())
				throw nullStringException();
			else if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
				return (convertChar(str));
			// Pseudo litterals detection
			else if (index >= 0 && index <= 7)
				return (printPseudoLitterals(atof(str.c_str())));
			// Float detection
			else if ( str.length() > 1 && str[str.length() - 1] == 'f' )
				return (convertDouble(str));
			// Int detection
			else if ( (str[0] == '+' || str[0] == '-') && (str.length() > 1)
				&& (countDigits(str) == str.length() - 1) )
				return (convertInt(str));
			else if ( countDigits(str) == str.length() )
				return (convertInt(str));
			else
				throw invalidLitteralExcepetion();
		case 1:
			// Double detection
			if (index == -1 && str.length() >= 2)
				return (convertDouble(str));
			else if (str.length() == 1)
				return (convertChar(str));
			else
				throw invalidLitteralExcepetion();
		default:
			throw invalidLitteralExcepetion();
	}
}

long unsigned int		ScalarConverter::countDigits(std::string str)
{
	int	count = 0;
	for (unsigned short i = 0; i < str.length(); i++)
		if (isdigit(str[i]))
			count++;
	return (count);
}

void	ScalarConverter::convert(std::string str)
{
	try
	{
		detect(str);
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}
	return ;
}