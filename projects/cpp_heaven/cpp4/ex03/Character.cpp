/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:03:41 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/08 20:22:52 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

Character::Character(const std::string& name) : _name(name)
{
	// std::cout << MAGENTA << "Character name constructor : " << name << RESET << std::endl;
	for (unsigned short i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return;
}

Character::Character(const Character& input) : _name(input._name)
{
	// std::cout << MAGENTA << "Character copy constructor : " << input.getName() << RESET << std::endl;
	for(int i = 0; i < 4; i++)
		if (input._inventory[i])
			this->_inventory[i] = input._inventory[i]->clone();
}

Character::~Character(void)
{
	// std::cout << MAGENTA << "Character destructor " << this->getName() << RESET << std::endl;
	for (unsigned short i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{	
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	return;
}

Character&	Character::operator=(const Character& input)
{
	this->_name = input.getName();
	for (unsigned short i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (input._inventory[i])
			this->_inventory[i] = input._inventory[i]->clone();
		else
			this->_inventory[i] = 0;
	}
	return (*this);
}

std::string	const	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << RED << "Error : out of band slot ! Use value between 0 and 3." << RESET << std::endl;
		return;
	}
	else
	{
		if (this->_inventory[idx] != NULL)
			this->_inventory[idx]->use(target);
		else
			std::cout << YELLOW << "You have no Materia at this inventory slot." << RESET << std::endl;
	}
	return;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << RED << "Error : out of band slot ! Use value between 0 and 3." << RESET << std::endl;
		return;
	}
	else if (this->_inventory[idx] == NULL)
	{
		std::cout << YELLOW << "Nothing to unequip on this slot." << RESET << std::endl;
		return;
	}
	else
	{
		std::cout << RESET << "Unequiped : " << this->_inventory[idx]->getType() << RESET << std::endl;
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
	return;
}

void	Character::equip(AMateria* m)
{
	for (unsigned short	i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m->clone();
			return;
		}
	}
	std::cout << RED << "Error : not enough inventory space left to equip Materias !" << RESET << std::endl;
	return;
}
