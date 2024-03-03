/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:44:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/29 01:32:37 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << MAGENTA << "Animal default constructor" << RESET << std::endl;
	return;
}

Animal::Animal(std::string type)
{
	std::cout << MAGENTA << "Animal constructor" << type << RESET << std::endl;
	this->_type = type;
	return;
}

Animal::~Animal(void)
{
	std::cout << MAGENTA << "Animal destructor " << getType() << RESET << std::endl;
	return;
}

Animal::Animal(const Animal& input)
{
	std::cout << MAGENTA << "Animal copy constructor " << input.getType() << RESET << std::endl;
	*this = input;
	return;
}

Animal& Animal::operator=(const Animal& input)
{
	// Assignment operator overload
	this->_type = input._type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void		Animal::setType(std::string type)
{
	this->_type = type;
	return;
}

void		Animal::makeSound(void) const
{
	return;
}
