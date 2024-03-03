/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:44:22 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/29 02:49:09 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << MAGENTA << "WrongCat default constructor" << RESET << std::endl;
	this->setType("WrongCat");
	return;
}

WrongCat::WrongCat(const WrongAnimal& input)
{
	std::cout << MAGENTA << "WrongCat copy constructor " << input.getType() << RESET << std::endl;
	WrongAnimal::operator=(input);
	this->setType("WrongCat");
	return;
}

WrongCat::~WrongCat(void)
{
	std::cout << MAGENTA << "WrongCat destructor " << this->getType() << RESET << std::endl;
	return;
}

WrongCat&	WrongCat::operator=(const WrongCat& input)
{
	this->setType(input.getType());
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << RESET << "WrongCat Nya~~ 🐈" << RESET << std::endl;
	return;
}