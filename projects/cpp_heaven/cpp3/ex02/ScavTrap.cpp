/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:44:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/27 14:04:07 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << MAGENTA << "ScavTrap Default constructor " << RESET << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << MAGENTA << "ScavTrap Constructor " << name << RESET << std::endl;
	this->_name = name;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << MAGENTA << "ScavTrap Destructor " << this->_name << RESET << std::endl;
	return;
}

ScavTrap::ScavTrap(const ClapTrap& input)
{
	std::cout << MAGENTA << "ScavTrap Copy constructor " << this->_name << RESET << std::endl;
	ClapTrap::operator=(input);
	return;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& input)
{
	ClapTrap::operator=(input);
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hit_point == 0 || this->_energy_point == 0)
	{
		std::cout << RED << this->_name << " cAn'T aTtacK : " << target << ", " << RESET;
		std::cout << YELLOW << this->_name << " lAckKS HIt pOINs or eNergy pOIntS !" << RESET << std::endl;
		this->printStats();
		return;
	}
	std::cout << RESET << "ScavTrap " << this->_name;
	std::cout << RESET << ", aTtACks " << target;
	std::cout << RESET << " caUsIng " << this->_attack_damage;
	std::cout << RESET << " PoinTS Of daMAgE !" << RESET << std::endl;
	this->_energy_point--;
	return;
}

void	ScavTrap::guardGate(void)
{
	static	short	lever = 0;
	lever % 2 == 0 ? (std::cout << RESET << "ScavTrap " << this->_name << " has enabled his GateKeeper mode !" << std::endl) : (std::cout << RESET << "ScavTrap " << this->_name << " has disabled his GateKeeper mode !" << std::endl);
	lever++;
	return;
}
