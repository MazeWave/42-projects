/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:05:38 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/29 21:34:19 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << MAGENTA << "Brain default constructor" << RESET << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = "";
	return;
}

Brain::Brain(const Brain& input)
{
	std::cout << MAGENTA << "Brain copy constructor" << RESET << std::endl;
	*this = input;
	return;
}

Brain::~Brain(void)
{
	std::cout << MAGENTA << "Brain default destructor" << RESET << std::endl;
	return;
}

Brain&	Brain::operator=(const Brain& input)
{
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = input.ideas[i];
	return (*this);
}
