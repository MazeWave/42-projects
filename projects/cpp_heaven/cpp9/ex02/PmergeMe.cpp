/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:57:23 by ldalmass          #+#    #+#             */
/*   Updated: 2025/02/03 17:00:29 by ldalmass         ###   ########.fr       */
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
