/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:13:44 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/08 21:03:04 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << MAGENTA << "Dog default constructor" << RESET << std::endl;
	this->setType("Dog");
	this->_brain = new Brain();
	return;
}
Dog::Dog(const Animal& input)
{
	std::cout << MAGENTA << "Dog copy constructor " << input.getType() << RESET << std::endl;
	Animal::operator=(input);
	this->setType("Dog");
	return;
}

Dog::~Dog(void)
{
	std::cout << MAGENTA << "Dog destructor " << this->getType() << RESET << std::endl;
	delete this->_brain;
	return;
}

Dog&	Dog::operator=(const Dog& input)
{
	this->setType(input.getType());
	this->_brain = new Brain(*(input._brain));
	return (*this);
}

void	Dog::makeSound(void)
{
	std::cout << RESET << "GRRRRR WOOF WOOF 🐶" << RESET << std::endl;
	return;
}
