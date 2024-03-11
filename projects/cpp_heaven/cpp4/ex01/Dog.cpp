/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:13:44 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/11 17:45:15 by ldalmass         ###   ########.fr       */
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
Dog::Dog(const Dog& input) : Animal()
{
	std::cout << MAGENTA << "Dog copy constructor " << input.getType() << RESET << std::endl;
	this->operator=(input);
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
