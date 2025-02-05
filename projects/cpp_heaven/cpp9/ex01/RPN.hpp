/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2025/02/05 16:37:04 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/************* STANDARD LIBRARIES ***************/
# include <iostream>
# include <iomanip>
# include <fstream>		// for std::ifstream
# include <string>
# include <exception>
# include <algorithm>	// for rand() / srand() / std::generate()

# include <stack>		// for std::stack
# include <cstdlib>
# include <typeinfo>

/******************* CLASSES ********************/
class	RPN
{
	private:
	std::stack<double>	_stack;

	public:
	~RPN(void);
	RPN(void);
	RPN(const char *raw_expression);
	RPN(const RPN &input);

	RPN&	operator=(const RPN &input);

	static std::string	trimLine(const std::string str);
	static char			whatOperand(const char c);
	void				parseExpression(const std::string expr);
	void				getExpression(const char *raw_expression);
	void				doMath(const char operand);
	std::stack<double>	getStack(void);

	class		InvalidCharacterInExpressionException: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("\033[31mThe expression contains invalid characters !\033[0m");
		};
	};
	class		DivideByZeroException: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("\033[31mYou can not divide by 0 !\033[0m");
		};
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

# define JOLLY 0