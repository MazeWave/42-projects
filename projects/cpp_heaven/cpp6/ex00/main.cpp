/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/07 02:56:33 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int		main(int argc, char **argv)
{
	std::string	str;

	if (argc != 2)
	{
		std::cout << YELLOW << "Usage: ./ScalarConverter [number]" << RESET << std::endl;
		return (1);
	}

	// Argument
	str = argv[1];
	ScalarConverter::convert(str);
	/*
	// Numbers
	std::cout << "Number tests -----------------------------------------------" << std::endl;
	ScalarConverter::convert("1");
	ScalarConverter::convert("0");
	ScalarConverter::convert("-1");
	ScalarConverter::convert("+42");
	ScalarConverter::convert("42f");
	ScalarConverter::convert("42.42f");
	ScalarConverter::convert("-42.42f");
	ScalarConverter::convert("-0.42f");
	ScalarConverter::convert(".42");
	ScalarConverter::convert("42.");
	std::cout << std::endl;

	// Pseudo litterals
	std::cout << "Pseudo litterals tests ------------------------------------" << std::endl;
	ScalarConverter::convert("nan");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("inf");
	ScalarConverter::convert("inff");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("-inff");
	std::cout << std::endl;

	// Chars
	std::cout << "Chars tests -----------------------------------------------" << std::endl;
	ScalarConverter::convert("a");
	ScalarConverter::convert("z");
	ScalarConverter::convert("A");
	ScalarConverter::convert("Z");
	ScalarConverter::convert("az");
	ScalarConverter::convert("AZ");
	std::cout << std::endl;

	// Doubled point
	std::cout << "Doubled point tests ---------------------------------------" << std::endl;
	ScalarConverter::convert("42..");
	ScalarConverter::convert("..42");
	ScalarConverter::convert("42..42");
	ScalarConverter::convert(".42..42");
	ScalarConverter::convert("42.42.");
	ScalarConverter::convert("42..4.2");
	std::cout << std::endl;

	// Comma
	std::cout << "Comma tests -----------------------------------------------" << std::endl;
	ScalarConverter::convert("42,");
	ScalarConverter::convert(",42");
	ScalarConverter::convert("42,42");
	std::cout << std::endl;

	// Overflow / Underflow
	std::cout << "Overflow / Underflow tests --------------------------------" << std::endl;
	ScalarConverter::convert("2147483647");
	ScalarConverter::convert("-2147483648");
	ScalarConverter::convert("2147483648");		// Overflow
	ScalarConverter::convert("-2147483649");	// Underflow
	ScalarConverter::convert("-1000000000000000");
	ScalarConverter::convert("1000000000000000");
	ScalarConverter::convert("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999f");
	std::cout << std::endl;

	// Others
	std::cout << "Others tests ----------------------------------------------" << std::endl;
	ScalarConverter::convert("");
	ScalarConverter::convert(" ");
	ScalarConverter::convert(".");
	ScalarConverter::convert(",");
	ScalarConverter::convert("+");
	ScalarConverter::convert("-");
	ScalarConverter::convert("-1111-1");
	ScalarConverter::convert("+1111-1");
	ScalarConverter::convert("1111-1");
	ScalarConverter::convert("-1111a1");
	ScalarConverter::convert("+1111a1");
	ScalarConverter::convert("1111a1");
	std::cout << std::endl;
	*/
	return (0);
}
