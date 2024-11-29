/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/27 22:09:55 by ldalmass         ###   ########.fr       */
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
# include <algorithm>	// for rand() / srand()

/******************* CLASSES ********************/
class	numberNotFoundException : public std::exception
{
	virtual const char*	what() const	throw()
	{
		return ("\033[31mNumber not found in the container !\033[0m");
	}
};

/****************** FUNCTIONS *******************/
template <typename T>
int	easyfind(T &container, int to_find)
{
	typename T::iterator	iter = std::find(container.begin(), container.end(), to_find);
	if (iter == container.end())
		throw numberNotFoundException();
	else
		return (*iter);
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