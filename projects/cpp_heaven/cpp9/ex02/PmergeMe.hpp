/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2025/02/07 20:23:40 by ldalmass         ###   ########.fr       */
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
# include <ctime>		// for clock_t
# include <cstdlib>
# include <string.h>

/******************* CLASSES ********************/
class	PmergeMe
{
	private:
	std::vector<unsigned long>	_vdata;
	std::deque<unsigned long>	_ddata;

	public:
	~PmergeMe(void);
	PmergeMe(void);
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe &input);

	PmergeMe&	operator=(const PmergeMe &input);

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
	merge_sort(start, mid);	// Sort left half
	merge_sort(mid, end);	// Sort right half

	// Merge the two sorted halves
	typedef typename Iterator::value_type ValueType;
	std::deque<ValueType> temp;

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

template <typename Container>
Container	merge_insertion_sort(Container input)
{
	unsigned short	size = input.size();
	unsigned long	left_over = -1;

	Container	max;
	Container	min;

/*STEP 1*/

	// Get the left_over
	if (size % 2 == 1)
	{
		left_over = input.back();
		input.pop_back();
	}

/*STEP 2*/

	// Create pairs and move the larger number to max and the lower number in min for each pairs
	while (input.size() > 1)
	{
		unsigned long	a = input.back();
		input.pop_back();
		unsigned long	b = input.back();
		input.pop_back();
		unsigned long	c;
	
		if (a < b)
		{
			c = a;
			a = b;
			b = c;
		}

		max.push_back(a);
		min.push_back(b);
	}

/*STEP 3*/

	// Sort min recursively using merge sort
	merge_sort(max.begin(), max.end());

	/*STEP 4*/

	// Copy the sorted max container in the _vdata, then insert the first value of min in it if we should
	input = max;
	if (input[0] >= min[0])
	{
		input.insert(input.begin(), min[0]);
		min = Container(min.begin()+1, min.end());
	}

/*STEP 5*/

	unsigned short	maxJacobVal = 0;
	
	while (PmergeMe::GetJacobNumber(++maxJacobVal) < min.size())
		continue;

	std::vector<unsigned long>	JacobList;

	for (unsigned short i = 3; i < maxJacobVal; i++)
		JacobList.push_back(PmergeMe::GetJacobNumber(i));

	// Insert value with jacob list
	for(unsigned short i = 0; i < JacobList.size(); i++)
		input.insert(std::lower_bound(input.begin(), input.end(), min[JacobList[i]]), min[JacobList[i]]);	// std::lower_bound() use binary search for efficiency

	for (unsigned short i = 0; i < min.size(); i++)
	{
		if (JacobList.end() != std::find(JacobList.begin(), JacobList.end(), i))
			continue;
		else
			input.insert(std::lower_bound(input.begin(), input.end(), min[i]), min[i]);
	}

/* STEP 6 */

	if (left_over != static_cast<unsigned long>(-1))
		input.insert(std::lower_bound(input.begin(), input.end(), left_over), left_over);

	return (input);
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