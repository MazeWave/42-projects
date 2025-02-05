/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2025/02/05 01:13:27 by ldalmass         ###   ########.fr       */
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

	void	PopulateContainers(int argc, char **argv);

	void	VectorMergeInstertSort(void);
	// void	DequeMergeInstertSort();

	static unsigned long	Power(unsigned long n, const unsigned short pow);
	static unsigned long	GetJacobNumber(unsigned long n);
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
	return ;
}

template <typename T>
bool	IsSorted(const T &container)
{
	unsigned short	size = container.size();
	T				sorted = container;

	// Create our sorted container
	std::sort(sorted.begin(), sorted.end());

	// Compare it with the current container
	for (unsigned short i = 0; i < size; i++)
		if (container[i] != sorted[i])
			return (false);
	return (true);
}

template <typename Iterator>
bool	IsSorted(const Iterator start, const Iterator end)
{
	unsigned long	n = *start;

	// Compare it with the current container
	while (start != end - 1)
	{
		if (n > *start + 1)
			return (false);
		++start;
		n = *start;
	}
	return (true);
}

template <typename Iterator>
void merge_sort(Iterator start, Iterator end)
{
	// Basic tests
	// end - start : The distance between the to iterator hence the size of the container
	if (end - start <= 1)
		return ;
	if (end - start == 2)
	{
		if (*(start + 1) < *start)
			std::iter_swap(start, start + 1);
		return ;
	}

	// Recursively split the range in two
	Iterator mid = start + (end - start) / 2;	// mid = container.begin() + container.size() / 2
	mergeSort(start, mid);	// Sort left half
	mergeSort(mid, end);	// Sort right half

	// Merge the two sorted halves
	typedef typename Iterator::value_type ValueType;
	std::vector<ValueType> temp;

	Iterator left = start;
	Iterator right = mid;


	while (left != mid && right != end)
	{
		if (*left < *right)
		{
			temp.push_back(*left);
			++left;
		}
		else
		{
			temp.push_back(*right);
			++right;
		}
	}

	// If any elements remain in the left half, add them
	while (left != mid)
	{
		temp.push_back(*left);
		++left;
	}

	// If any elements remain in the right half, add them
	while (right != end)
	{
		temp.push_back(*right);
		++right;
	}

	// Copy the sorted temp vector back into the original container
	std::copy(temp.begin(), temp.end(), start);
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