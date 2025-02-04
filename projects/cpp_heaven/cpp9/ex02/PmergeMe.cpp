/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:57:23 by ldalmass          #+#    #+#             */
/*   Updated: 2025/02/04 19:17:52 by ldalmass         ###   ########.fr       */
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

// std::vector<unsigned long>	PmergeMe::RecursiveSort(std::vector<unsigned long> input)
// {
// 	unsigned short				size = input.size();
// 	std::vector<unsigned long>	temp;

// 	// Recursive pairs creation
// 	if (size > 2)
// 	{
// 		temp.push_back(input.back());
// 		input.pop_back();
// 		temp.push_back(input.back());
// 		input.pop_back();
// 		PrintContainer(input, "input ");
// 		PrintContainer(temp, "temp ");
// 		RecursiveSort(input);
// 	}

// 	// Sort the current pair
// 	// if (temp.size() == 2)
// 	// {
// 	// 	std::vector<unsigned long>::iterator	start = temp.begin();
// 	// 	std::vector<unsigned long>::iterator	end = temp.end();
// 	// 	if (*start > *start+1)
// 	// 	{
// 	// 		std::vector<unsigned long>::iterator	c;
// 	// 		c = start;
// 	// 		start = start+1;
// 	// 		start+1 = c;
// 	// 	}
// 	// }
// 	return (temp);
// }

void	PmergeMe::VectorMergeInstertSort(void)
{
	unsigned short	size = this->_vdata.size();
	unsigned long	left_over = -1;

	std::vector<unsigned long>	max;
	std::vector<unsigned long>	min;

	// std::vector<unsigned long>::const_iterator	start = this->_vdata.begin();
	// std::vector<unsigned long>::const_iterator	end = this->_vdata.end();

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


	// Sort min and max 
	std::sort(max.begin(), max.end());
	std::sort(min.begin(), min.end());

	// Re-input left over in 
	// if (left_over != (unsigned long)-1)
	// {
		
	// }

	std::cout << GREEN << "left_over : " << left_over << RESET << std::endl;

	PrintContainer(max, "max :           ");
	PrintContainer(min, "min :           ");

	return ;
}