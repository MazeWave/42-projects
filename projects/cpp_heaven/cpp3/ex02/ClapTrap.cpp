/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:44:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/28 02:52:55 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << MAGENTA << "ClapTrap Default constructor " << RESET << std::endl;
	this->_name = "";
	this->_hit_point = 100;
	this->_energy_point= 100;
	this->_attack_damage = 30;
	return;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << MAGENTA << "ClapTrap Constructor " << name << RESET << std::endl;
	this->_name = name;
	this->_hit_point = 100;
	this->_energy_point= 50;
	this->_attack_damage = 20;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << MAGENTA << "ClapTrap Destructor " << this->_name << RESET << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap& input)
{
	std::cout << MAGENTA << "ClapTrap Copy constructor " << input._name << RESET << std::endl;
	*this = input;
	return;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& input)
{
	this->_name = input._name;
	this->_hit_point = input._hit_point;
	this->_energy_point= input._energy_point;
	this->_attack_damage = input._attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hit_point == 0 || this->_energy_point == 0)
	{
		std::cout << RED << this->_name << " can't attack : " << target << ", " << RESET;
		std::cout << YELLOW << this->_name << " lacks Hit points or Energy points !" << RESET << std::endl;
		this->printStats();
		return;
	}
	std::cout << RESET << "ClapTrap " << this->_name;
	std::cout << RESET << ", attacks " << target;
	std::cout << RESET << " causing " << this->_attack_damage;
	std::cout << RESET << " points of damage !" << RESET << std::endl;
	this->_energy_point--;
	return;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_point == 0)
	{
		std::cout << YELLOW << this->_name << " already at 0 Hit points" << RESET << std::endl;
		return;
	}
	std::cout << RESET << this->_name << " has taken " << amount << " damages !" << RESET << std::endl;
	std::cout << "    " << this->_hit_point << " -> ";
	this->_hit_point -= amount;
	std::cout << this->_hit_point << RESET << std::endl;
	return;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_point == 0 || this->_energy_point == 0)
	{
		std::cout << RED << this->_name << " can't be repaired : " << RESET;
		std::cout << YELLOW << this->_name << " lacks Hit points or Energy points !" << RESET << std::endl;
		this->printStats();
		return;
	}
	std::cout << RESET << this->_name << " repaired " << amount << " Hit points !" << RESET << std::endl;
	std::cout << "    " << this->_hit_point << " -> ";
	if (amount > 10)
		this->_hit_point = 10;
	else
		this->_hit_point += amount;
	this->_energy_point--;
	std::cout << this->_hit_point << RESET << std::endl;
	return;
}

void	ClapTrap::printStats(void)
{
	size_t	tiret = this->_name.length() + 12;

	std::cout << BLUE << "----- " << this->_name << " -----" << BLUE << std::endl;
	std::cout << "Hit points : " << this->_hit_point << std::endl;
	std::cout << "Energy points : " << this->_energy_point << std::endl;
	std::cout << "Attack damage : " << this->_attack_damage << std::endl;
	for (size_t i = 0; i < tiret; i++)
		std::cout << "-";
	std::cout << RESET << std::endl;
	return;
}
