/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/30 17:49:25 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/************* STANDARD LIBRARIES ***************/
# include <iostream>
# include <string>
# include <exception>
# include <limits>		// for std::numeric_limits<int>
# include <algorithm>	// for rand() / srand() / std::generate()

# include <stack>		// for std::stack

/******************* CLASSES ********************/
template <typename T>
class   MutantStack : public std::stack<T>
{
	public:
	~MutantStack() {};
	MutantStack() : std::stack<T>() {};
	MutantStack(const &input) : std::stack<T>(const &input) {};
	MutantStack	&operator=(const MutantStack &input)
	{
		if (*this != input)
			std::stack<T>::operator=(input);
		return (*this);
	}

	
};

class	outOfRangeException : public std::exception
{
	virtual const char*	what() const	throw()
	{
		return ("\033[31m❌ Number out of range !\033[0m");
	}
};

/****************** FUNCTIONS *******************/
// template <typename T>
// int	easyfind(T &container, int to_find)
// {
// 	typename T::iterator	iter = std::find(container.begin(), container.end(), to_find);
// 	if (iter == container.end())
// 		throw numberNotFoundException();
// 	else
// 		return (*iter);
// };

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