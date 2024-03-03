/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 01:12:18 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/29 02:36:49 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << MAGENTA << "Cat default constructor" << RESET << std::endl;
	this->setType("Cat");
	return;
}

Cat::Cat(const Animal& input)
{
	std::cout << MAGENTA << "Cat copy constructor " << input.getType() << RESET << std::endl;
	Animal::operator=(input);
	this->setType("Cat");
	return;
}

Cat::~Cat(void)
{
	std::cout << MAGENTA << "Cat destructor " << this->getType() << RESET << std::endl;
	return;
}

Cat&	Cat::operator=(const Cat& input)
{
	this->setType(input.getType());
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << RESET << "Nya~~ 🐈" << RESET << std::endl;
	return;
}