/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:13:44 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/11 16:42:07 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << MAGENTA << "Dog default constructor" << RESET << std::endl;
	this->setType("Dog");
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
	return;
}

Dog&	Dog::operator=(const Dog& input)
{
	this->setType(input.getType());
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << RESET << "GRRRRR WOOF WOOF 🐶" << RESET << std::endl;
	return;
}
