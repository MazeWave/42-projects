/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:57:23 by ldalmass          #+#    #+#             */
/*   Updated: 2025/02/05 01:13:29 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(int argc, char **argv)
{

	PopulateContainers(argc, argv);
	PrintContainer(this->_vdata, "Vector :        ");
	PrintContainer(this->_ddata, "Deque :         ");

	VectorMergeInstertSort();
	PrintContainer(this->_vdata, "Vector :        ");

	return ;
}

PmergeMe::PmergeMe(const PmergeMe &input)
{
	*this = input;
	return ;
}

// PmergeMe&	PmergeMe::operator=(const PmergeMe &input)
// {
// 	// this->_data = input.getData();
// 	return (*this);
// }

void	PmergeMe::PopulateContainers(int argc, char **argv)
{
	for (unsigned short i = 1; i < argc; i++)
	{
		this->_vdata.push_back(std::strtol(argv[i], 0, 10));
		this->_ddata.push_back(std::strtol(argv[i], 0, 10));
	}
	return ;
}

unsigned long	PmergeMe::Power(unsigned long n, const unsigned short pow)
{
	for (unsigned short i = 1; i < pow; i++)
		n = n * n;
	return (n);
}

unsigned long	PmergeMe::GetJacobNumber(unsigned long n)
{
	if (n <= 1)
		return (n);
	return (GetJacobNumber(n - 1) + 2 * GetJacobNumber(n - 2));
}

void	PmergeMe::VectorMergeInstertSort(void)
{
	unsigned short	size = this->_vdata.size();
	unsigned long	left_over = -1;

	std::vector<unsigned long>	max;
	std::vector<unsigned long>	min;

	// Remove and store last element
	if (size % 2 == 1)
	{
		left_over = this->_vdata.back();
		this->_vdata.pop_back();
	}

	// Create pairs and move the larger number to max and lower number in min for each pairs
	while (this->_vdata.size() > 1)
	{
		unsigned long	a = this->_vdata.back();
		this->_vdata.pop_back();
		unsigned long	b = this->_vdata.back();
		this->_vdata.pop_back();
		unsigned long	c;
	
		if (a < b)
		{
			c = a;
			a = b;
			b = c;
		}

		std::cout << GREEN << "a : " << a << " b : " << b << RESET << std::endl;

		max.push_back(a);
		min.push_back(b);
	}

	PrintContainer(max, "max :           ");
	PrintContainer(min, "min :           ");


	// Sort min and max recursively using merge sort
	merge_sort(max.begin(), max.end());
	merge_sort(min.begin(), min.end());

	// Copy the sorted max container in the _vdata, then insert the first value of min in it
	this->_vdata = max;
	this->_vdata.insert(this->_vdata.begin(), min[0]);
	min = std::vector<unsigned long>(min.begin()+1, min.end());
	

	// Re-input left over in 
	// if (left_over != (unsigned long)-1)
	// {
		
	// }

	std::cout << GREEN << "left_over : " << left_over << RESET << std::endl;

	PrintContainer(max, "max :           ");
	PrintContainer(min, "min :           ");

	return ;
}