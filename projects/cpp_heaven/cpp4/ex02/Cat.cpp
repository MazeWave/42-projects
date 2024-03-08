/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 01:12:18 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/08 21:06:28 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << MAGENTA << "Cat default constructor" << RESET << std::endl;
	this->setType("Cat");
	this->_brain = new Brain();
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
	delete this->_brain;
	return;
}

Cat&	Cat::operator=(const Cat& input)
{
	this->setType(input.getType());
	this->_brain = new Brain(*(input._brain));
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << RESET << "Nya~~ 🐈" << RESET << std::endl;
	return;
}