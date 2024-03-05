/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:28:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/05 17:49:02 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

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
            return (this->_learned_materias[i]);
    }
    std::cout << RED << "Error : no Materia found for type : " << type << RESET << std::endl;
    return (0);
}
