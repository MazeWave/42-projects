/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:28:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/06 22:56:08 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << MAGENTA << "MateriaSource default constructor" << RESET << std::endl;
	for (unsigned short i = 0; i < 4; i++)
		this->_learned_materias[i] = NULL;
	return;
}

MateriaSource::MateriaSource(const MateriaSource& input)
{
	std::cout << MAGENTA << "MateriaSource copy constructor" << RESET << std::endl;
	*this = input;
	return;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << MAGENTA << "MateriaSource destructor" << RESET << std::endl;
	// for (unsigned short i = 0; i < 4; i++)
	// 	delete this->_learned_materias[i];
	return;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& input)
{
	for (unsigned short i = 0; i < 4; i++)
		this->_learned_materias[i] = input._learned_materias[i];
	return (*this);
}

void    MateriaSource::learnMateria(AMateria* m)
{
    for (unsigned short i = 0; i < 4; i++)
    {
        if (this->_learned_materias[i] != NULL)
        {
            std::cout << RESET << "Learned new Materia : " << "type" << RESET << std::endl;
            this->_learned_materias[i] = m;
            return;
        }
    }
    std::cout << RED << "Error : not enough space to learn more Materias !" << RESET << std::endl;
    return;
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    for (unsigned short i = 0; i < 4; i++)
    {
        if (this->_learned_materias[i]->getType() == type)
            return (this->_learned_materias[i]->clone());
    }
    std::cout << RED << "Error : no Materia found for type : " << type << RESET << std::endl;
    return (0);
}
