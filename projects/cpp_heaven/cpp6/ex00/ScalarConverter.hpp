/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/07 00:35:23 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************* STANDARD LIBRARIES ***************/
# pragma once
# include <iostream>
# include <string>
# include <exception>
# include <climits>
# include <cfloat>
# include <cstdlib>
# include <algorithm>
# include "ScalarConverter.hpp"

/******************* CLASSES ********************/

class   ScalarConverter
{
	public:
	static void	convert(std::string str);

	private:
	static void	detect(std::string str);
	static void	convertInt(std::string str);
	static void	convertDouble(std::string str);
	static void	convertChar(std::string str);
	static void printConverted(char c, int i, float f, double d);
	static void	printPseudoLitterals(double d);
	static bool	checkOOB(double d, double min, double max);
	static long unsigned int	countDigits(std::string str);

	// Dummy constructor / destructor
	~ScalarConverter(void) { return ; };
	ScalarConverter(void) { return ; };

	// Exceptions
	class	nullStringException : public std::exception
	{
		const char *	what() const throw ()
		{
			return ("Input string is empty !");
		}
	};
	class	invalidLitteralExcepetion : public std::exception
	{
		const char *	what() const throw ()
		{
			return ("Invalid Litteral expression !");
		}
	};
};

/****************** FUNCTIONS *******************/

/******************* COLORS *********************/
# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"
# define CYAN		"\033[36m"
# define MAGENTA	"\033[35m"
# define YELLOW		"\033[33m"
# define BLACK		"\033[30m"
# define WHITE		"\033[37m"

# define DEBUG 0