/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:44:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/07 17:57:10 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << MAGENTA << "Ice default constructor" << RESET << std::endl;
	return;
}

Ice::Ice(const Ice& input) : AMateria(input.getType())
{
	std::cout << MAGENTA << "Ice copy constructor" << RESET << std::endl;
	// *this = input;
	return;
}

Ice::~Ice(void)
{
	std::cout << MAGENTA << "Ice destructor" << RESET << std::endl;
	return;
}

Ice&		Ice::operator=(const Ice& input)
{
	AMateria::operator=(input);
	return (*this);
}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter& target)
{
	std::cout << RESET << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
	return;
}
