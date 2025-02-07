/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:57:23 by ldalmass          #+#    #+#             */
/*   Updated: 2025/02/07 20:06:42 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::clock_t	startTime;
	std::clock_t	endTime;
	double			elapsed_us;

	PopulateContainers(argc, argv);
	// PrintContainer(this->_vdata, "Vector :        ");
	// PrintContainer(this->_ddata, "Deque :         ");

	// std::vector sort
	startTime = std::clock();
	// VectorMergeInstertSort();
	this->_vdata = merge_insertion_sort(this->_vdata);
	endTime = std::clock();
	elapsed_us = (endTime - startTime) / static_cast<double>(CLOCKS_PER_SEC) * 1000000.0;	// * 1000000.0
	// PrintContainer(this->_vdata, "Vector :        ");
	std::cout << "Time to process a range of " << argc << " elements with std::vector : " << elapsed_us << "μs" << std::endl;

	// std::deque sort
	startTime = std::clock();
	this->_ddata = merge_insertion_sort(this->_ddata);
	// DequeMergeInstertSort();
	endTime = std::clock();
	elapsed_us = (endTime - startTime) / static_cast<double>(CLOCKS_PER_SEC) * 1000000.0;
	// PrintContainer(this->_ddata, "Deque :         ");
	std::cout << "Time to process a range of " << argc << " elements with std::deque  : " << elapsed_us << "μs" << std::endl;

	if (IsSorted(this->_vdata) == true)
		std::cout << GREEN << "DATA SORTED FOR std::vector" << RESET << std::endl;
	else
		std::cout << RED << "DATA NOT SORTED FOR std::vector" << RESET << std::endl;

	if (IsSorted(this->_ddata) == true)
		std::cout << GREEN << "DATA SORTED FOR std::deque" << RESET << std::endl;
	else
		std::cout << RED << "DATA NOT SORTED FOR std::deque" << RESET << std::endl;


	return ;
}

PmergeMe::PmergeMe(const PmergeMe &input)
{
	*this = input;
	return ;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &input)
{
	if (this->_ddata != input._ddata || this->_vdata != input._vdata)
	{
		if (this->_ddata != input._ddata)
			this->_ddata = input._ddata;
		else
			this->_vdata = input._vdata;
	}
	return (*this);
}

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

	/*STEP 1*/

	// Get the left_over
	if (size % 2 == 1)
	{
		left_over = this->_vdata.back();
		this->_vdata.pop_back();
	}

	/*STEP 2*/

	// Create pairs and move the larger number to max and the lower number in min for each pairs
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

		// std::cout << GREEN << "a : " << a << " b : " << b << RESET << std::endl;

		max.push_back(a);
		min.push_back(b);
	}

	PrintContainer(max, "max :           ");
	PrintContainer(min, "min :           ");

	/*STEP 3*/

	// Sort min and max recursively using merge sort
	merge_sort(max.begin(), max.end());
	// merge_sort(min.begin(), min.end());

	/*STEP 4*/

	// Copy the sorted max container in the _vdata, then insert the first value of min in it if we should
	this->_vdata = max;
	if (this->_vdata[0] >= min[0])
	{
		this->_vdata.insert(this->_vdata.begin(), min[0]);
		min = std::vector<unsigned long>(min.begin()+1, min.end());
	}

	/*STEP 5*/

	unsigned short	maxJacobVal = 0;
	
	while (GetJacobNumber(++maxJacobVal) < min.size())
		continue;
	// maxJacobVal--;

	std::vector<unsigned long>	JacobList;

	for (unsigned short i = 3; i < maxJacobVal; i++)
		JacobList.push_back(GetJacobNumber(i));
	PrintContainer(JacobList, "Jacob LIST : ");
	PrintContainer(min, "minnnnnnnn : ");

	std::cout << CYAN << "prout 1" << RESET << std::endl;

	// Insert value with jacob list
	PrintContainer(this->_vdata, "BEFORE VECTOR");
	for(unsigned short i = 0; i < JacobList.size(); i++)
	{
		// std::lower_bound() use binary search for efficiency
		std::cout << MAGENTA << "Inserting at index " << JacobList[i] << " number " << min[JacobList[i]] << RESET << std::endl;
		this->_vdata.insert(std::lower_bound(_vdata.begin(), this->_vdata.end(), min[JacobList[i]]), min[JacobList[i]]);
		PrintContainer(this->_vdata, "       VECTOR");
	}

	std::cout << "min size : " << min.size() << std::endl;
	std::cout << CYAN << "prout 2" << RESET << std::endl;

	for (unsigned short i = 0; i < min.size(); i++)
	{
		std::cout << RED << i << RESET << std::endl;
		if (JacobList.end() != std::find(JacobList.begin(), JacobList.end(), i))
		{
			std::cout << MAGENTA << "SKIPPED " << i << " BECAUSE ALREADY ADDED BEFORE" << RESET << std::endl;
			continue;
		}
		else
		{
			this->_vdata.insert(std::lower_bound(_vdata.begin(), this->_vdata.end(), min[i]), min[i]);
		}
	}

	std::cout << "min size : " << min.size() << std::endl;

	/* STEP 6 */

	if (left_over != static_cast<unsigned long>(-1))
		this->_vdata.insert(std::lower_bound(_vdata.begin(), this->_vdata.end(), left_over), left_over);

	PrintContainer(max, "max :           ");
	PrintContainer(min, "min :           ");

	return ;
}