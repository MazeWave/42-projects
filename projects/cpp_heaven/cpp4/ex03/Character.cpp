/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:03:41 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/05 17:33:53 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

Character::Character(const std::string& name)
{
	std::cout << MAGENTA << "Character name constructor : " << name << RESET << std::endl;
	this->_name = name;
	// Initialize the inventory
	for (unsigned short i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return;
}

Character::Character(const Character& input)
{
	std::cout << MAGENTA << "Character copy constructor : " << input.getName() << RESET << std::endl;
	*this = input;
	return;
}

Character&	Character::operator=(const Character& input)
{
	this->_name = input.getName();
	this->_inventory = input._inventory;	//unsafe memory
	return (*this);
}

std::string	const	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::use(int idx, Character& target)
{
	std::cout << RESET << this->_name << " used " << this->_inventory[idx]->getType() << RESET << std::endl;
	return;
}

void	Character::unequip(int idx)
{
	std::cout << RESET << "Unequiped : " << this->_inventory[idx]->getType() << RESET << std::endl;
	this->_inventory[idx] = NULL;
	return;
}

void	Character::equip(AMateria* m)
{
	unsigned short	i = 0;

	for (unsigned short	i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			this->_inventory[i] = m;
			return;
		}
	}
	std::cout << RED << "Error : not enough inventory space left to equip Materias !" << RESET << std::endl;
	return;
}