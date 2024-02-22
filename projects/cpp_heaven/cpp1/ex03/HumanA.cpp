/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:07:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/16 17:11:55 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
    return;
}

HumanA::~HumanA(void)
{
    return;
}

void        HumanA::setName(std::string input)
{
    this->_name = input;
    return;
}

void        HumanA::setWeapon(Weapon input)
{
    this->_weapon = input;
    return;
}

std::string HumanA::getName(void)
{
    return (this->_name);
}

Weapon      HumanA::getWeapon(void)
{
    return (this->_weapon);
}

void        HumanA::attack(void)
{
    std::cout << GREEN << getName();
    std::cout << RESET << " attacks with their ";
    std::cout << RED << getWeapon().getType();
    std::cout << RESET << std::endl;
    return;
}