/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2025/02/03 17:00:44 by ldalmass         ###   ########.fr       */
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

# include <vector>		// for std::vector
# include <deque>		// for std::deque
# include <ctime>		// for timeval
# include <cstdlib>
# include <string.h>

/******************* CLASSES ********************/
class	PmergeMe
{
	private:
	PmergeMe(void);
	std::vector<unsigned long>	_vdata;
	std::deque<unsigned long>	_ddata;
	/*
	Both vectors and deques provide a very similar interface and can be used for similar purposes,
	but internally both work in quite different ways:
	While vectors use a single array that needs to be occasionally reallocated for growth,
	the elements of a deque can be scattered in different chunks of storage,
	with the container keeping the necessary information internally to provide direct access
	to any of its elements in constant time and with a uniform sequential interface (through iterators).
	Therefore, deques are a little more complex internally than vectors,
	but this allows them to grow more efficiently under certain circumstances,
	especially with very long sequences, where reallocations become more expensive.
	*/

	public:
	~PmergeMe(void);
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe &input);

	// PmergeMe&	operator=(const PmergeMe &input);

	// void	VectorMergeInstertSort();
	// void	DequeMergeInstertSort();

	void	PopulateContainers(int argc, char **argv);




};

/****************** FUNCTIONS *******************/
template <typename T>
void	PrintContainer(const T &container, const std::string message)
{
	typename T::const_iterator	start = container.begin();
	typename T::const_iterator	end = container.end();

	std::cout << message;
	std::cout << "[";
	while (start != end)
	{
		(start+1 != end) ? (std::cout << *start << ", ") : (std::cout << *start);
		++start;
	}
	std::cout << "]" << std::endl;
	std::cout << std::endl;
	return ;
}

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