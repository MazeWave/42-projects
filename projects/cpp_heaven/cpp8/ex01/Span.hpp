/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/12/10 17:26:05 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/************* STANDARD LIBRARIES ***************/
# include <iostream>
# include <string>
# include <exception>
# include <limits>		// for std::numeric_limits<int>
# include <map>			// for std::map
# include <list>		// for std::list
# include <vector>		// for std::vector
# include <algorithm>	// for rand() / srand() / std::generate()

/******************* CLASSES ********************/

class   Span
{
	private:
	size_t				_len;
	std::vector<int>	_data;

	// Dummy Contructor / Destructor
	Span(void) { return; };

	public:
	~Span(void) { return; };
	Span(size_t len);
	Span(const Span& input);
	Span&	operator=(const Span& input);

	int		shortestSpan(void);
	int		longestSpan(void);

	void	addNumber(int number);
	void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void	printNumbers(void);
	int		getLen(void);

	static unsigned int	dist(int a, int b);
};

class	outOfRangeException : public std::exception
{
	virtual const char*	what() const	throw()
	{
		return ("\033[31m❌ Number out of range !\033[0m");
	}
};

class	cannotFindShortestSpan : public std::exception
{
	virtual const char*	what() const	throw()
	{
		return ("\033[31m❌ Can not find the shortest span in the container !\033[0m");
	}
};

class	cannotFindLongestSpan : public std::exception
{
	virtual const char*	what() const	throw()
	{
		return ("\033[31m❌ Can not find the longest span in the container !\033[0m");
	}
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