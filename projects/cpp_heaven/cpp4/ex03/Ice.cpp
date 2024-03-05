/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:44:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/05 14:56:11 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

AMateria::AMateria(void)
{
	std::cout << MAGENTA << "AMateria default constructor" << RESET << std::endl;
	return;
}

AMateria::AMateria(const std::string& type)
{
	std::cout << MAGENTA << "AMateria constructor" << type << RESET << std::endl;
	this->_type = type;
	return;
}

AMateria::~AMateria(void)
{
	std::cout << MAGENTA << "AMateria destructor " << getType() << RESET << std::endl;
	return;
}

AMateria::AMateria(const AMateria& input)
{
	std::cout << MAGENTA << "AMateria copy constructor " << input.getType() << RESET << std::endl;
	*this = input;
	return;
}

AMateria& AMateria::operator=(const AMateria& input)
{
	// Assignment operator overload
	this->_type = input._type;
	return (*this);
}

std::string	const	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::setType(std::string type)
{
	this->_type = type;
	return;
}

AMateria*	AMateria::clone(void) const
{
	return (new AMateria(*this));
}

void	AMateria::use(int idx, ICharacter& target)
{
	std::cout << RESET << this->_name << " used " << target.getType() << RESET << std::endl;
	return;
}
