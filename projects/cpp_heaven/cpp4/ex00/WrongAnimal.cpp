/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:44:23 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/29 03:03:37 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << MAGENTA << "WrongAnimal default constructor" << RESET << std::endl;
	return;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << MAGENTA << "WrongAnimal constructor" << type << RESET << std::endl;
	this->_type = type;
	return;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << MAGENTA << "WrongAnimal destructor " << getType() << RESET << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal& input)
{
	std::cout << MAGENTA << "WrongAnimal copy constructor " << input.getType() << RESET << std::endl;
	*this = input;
	return;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& input)
{
	// Assignment operator overload
	this->_type = input._type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void		WrongAnimal::setType(std::string type)
{
	this->_type = type;
	return;
}

void		WrongAnimal::makeSound(void) const
{
	return;
}
