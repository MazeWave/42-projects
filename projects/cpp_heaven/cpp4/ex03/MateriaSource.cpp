/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:28:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/07 18:00:31 by ldalmass         ###   ########.fr       */
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
	for (unsigned short i = 0; i < 4; i++)
		if (this->_learned_materias[i] != NULL)
	 		this->_learned_materias[i] = input._learned_materias[i]->clone();
	return;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << MAGENTA << "MateriaSource destructor" << RESET << std::endl;
	for (unsigned short i = 0; i < 4; i++)
	{
		std::cout << i << std::endl;
		if (this->_learned_materias[i])
			delete this->_learned_materias[i];
		std::cout << "done\n";
	}
	return;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& input)
{
	for (unsigned short i = 0; i < 4; i++)
	{
		if (this->_learned_materias[i])
		{
			delete this->_learned_materias[i];
			this->_learned_materias[i] = NULL;
		}
		if (input._learned_materias[i] != NULL)
			this->_learned_materias[i] = input._learned_materias[i]->clone();
			// this->_learned_materias[i] = input._learned_materias[i]->clone();
	}
	return (*this);
}

void    MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << RED << "Error : the input Materia doesn't exist !" << RESET << std::endl;
		return;
	}
    for (unsigned short i = 0; i < 4; i++)
    {
        if (this->_learned_materias[i] == NULL)
        {
            std::cout << RESET << "Learned new Materia : " << m->getType() << RESET << std::endl;
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
        if (this->_learned_materias[i] && this->_learned_materias[i]->getType() == type)
		{
			std::cout << "ICI" << std::endl;
            return (this->_learned_materias[i]->clone());
			// return (this->_learned_materias[i]->clone());
		}
    }
    std::cout << RED << "Error : no Materia found for type : " << type << RESET << std::endl;
    return (NULL);
}
