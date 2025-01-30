/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:57:23 by ldalmass          #+#    #+#             */
/*   Updated: 2025/01/30 19:39:29 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN(void)
{
	return ;
}

RPN::RPN(const char *raw_expression)
{
	// Parse for illegal characters
	try { parseExpression(std::string(raw_expression)); }
	catch ( std::exception &error ) { std::cout << error.what() << std::endl; return ; }

	// Do the math
	try { getExpression(raw_expression); }
	catch ( std::exception &error ) { std::cout << error.what() << std::endl; return ; }

	return ;
}

RPN::RPN(const RPN &input)
{
	*this = input;
	return ;
}

std::string RPN::trimLine(const std::string str)
{
	std::string::const_iterator start = str.begin();
	std::string::const_iterator end = str.end();

	// Remove spaces at start
	while (start != str.end() && std::isspace(*start))
		++start;
	if (start == end)
		return ("");
	// Remove spaces at end
	do --end;
	while (end != start && std::isspace(*end));

	return (std::string(start, end + 1));
}

char	RPN::whatOperand(const char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (c);
	return ('\0');
}

void	RPN::parseExpression(const std::string expr)
{
	std::string	rpn = trimLine(expr);
	std::string::const_iterator	start = rpn.begin();
	std::string::const_iterator	end = rpn.end();

	if (rpn.size() == 0)
		throw InvalidCharacterInExpressionException();

	while (start != end)
	{
		if (!std::isspace(*start)
			&& !std::isdigit(*start)
			&& *start != '+'
			&& *start != '-'
			&& *start != '*'
			&& *start != '/'
			)
				throw InvalidCharacterInExpressionException();
		++start;
	}

	start = rpn.begin();
	end = rpn.end();

	return ;
}

void	RPN::doMath(const char operand)
{
	// if no numbers are provided, we assume to use 0 instead
	double	a = 0.0;
	double	b = 0.0;

	if (this->_stack.size() > 0)
	{
		a = this->_stack.top();
		this->_stack.pop();
	}
	if (this->_stack.size() > 0)
	{
		b = this->_stack.top();
		this->_stack.pop();
	}

	switch (operand)
	{
		case '+':
			JOLLY != 0 ? std::cout << b << " + " << a << " = " << b + a << std::endl : std::cout;
			this->_stack.push(b + a);
			break;
		case '-':
			JOLLY != 0 ? std::cout << b << " - " << a << " = " << b - a << std::endl : std::cout;
			this->_stack.push(b - a);
			break;
		case '*':
			JOLLY != 0 ? std::cout << b << " * " << a << " = " << b * a << std::endl : std::cout;
			this->_stack.push(b * a);
			break;
		case '/':
			if (a == 0.0)
				throw DivideByZeroException();
			JOLLY != 0 ? std::cout << b << " / " << a << " = " << b / a << std::endl : std::cout;
			this->_stack.push(b / a);
			break;
	}
	return ;
}

void	RPN::getExpression(const char *raw_expression)
{
	std::string	expr = trimLine(raw_expression);
	std::string	number;

	std::string::const_iterator	start = expr.begin();
	std::string::const_iterator	end = expr.end();

	if (JOLLY != 0)
		std::cout << CYAN << "Expression : \"" << expr << "\"" << RESET << std::endl;

	while (start != end)
	{
		// std::cout << YELLOW << "Current : '" << *start << "'" << RESET << std::endl;
		// Push our number in the stack
		if (std::isdigit(*start))
		{
			while (std::isdigit(*start))
				number = number + *start++;
			this->_stack.push(std::strtod(number.c_str(), 0));
			// std::cout << "Extracted : " << number << std::endl;
			number = "";
			continue;
		}
		
		// Do the math
		if (whatOperand(*start) != '\0')
			doMath(whatOperand(*start));

		++start;
	}

	JOLLY != 0 ? std::cout << CYAN << "Result : " << this->_stack.top() << RESET << std::endl : std::cout << this->_stack.top() << std::endl;

	return ;
}

// RPN&	RPN::operator=(const RPN &input)
// {
// 	// this->_data = input.getData();
// 	return (*this);
// }
