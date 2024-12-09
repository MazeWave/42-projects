/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/12/10 00:42:25 by ldalmass         ###   ########.fr       */
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
# include <list>		// for std::list
# include <vector>		// for std::vector

/******************* CLASSES ********************/
template <typename T>
class   MutantStack : public std::stack<T>
{
	public:
	~MutantStack() {};
	MutantStack() : std::stack<T>() {};
	MutantStack(const MutantStack &input) : std::stack<T>(input) {};
	MutantStack	&operator=(const MutantStack &input)
	{
		if (*this != input)
			std::stack<T>::operator=(input);
		return (*this);
	}

	// Defining our iterators
	// container_type::iterator reveal other hidden functions in the container, like iterators.
	typedef typename	std::stack<T>::container_type::iterator			iterator;
	typedef typename	std::stack<T>::container_type::const_iterator	const_iterator;

	iterator		begin() { return (std::stack<T>::c.begin()); };
	iterator		end() { return (std::stack<T>::c.end()); };
	const_iterator	begin() const { return (std::stack<T>::c.begin()); };
	const_iterator	end() const { return (std::stack<T>::c.end()); };
};

/****************** FUNCTIONS *******************/
template <typename T>
void	print_container(const T &container)
{
	typename T::const_iterator	it = container.begin();
	typename T::const_iterator	ite = container.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	return ;
};

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