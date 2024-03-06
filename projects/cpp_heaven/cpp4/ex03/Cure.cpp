/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:03:38 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/06 18:59:39 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << MAGENTA << "Cure default contructor" << RESET << std::endl;
	return;
}

Cure::Cure(const Cure& input) : AMateria(input)
{
	std::cout << MAGENTA << "Cure copy contructor" << RESET << std::endl;
	return;
}

Cure&		Cure::operator=(const Cure& input)
{
	AMateria::operator=(input);
	return (*this);
}

AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}

void		Cure::use(ICharacter& target)
{
	std::cout << RESET << "* heals " << target.getName() << " wounds *" << RESET << std::endl;
	return;
}
