/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:07:10 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/16 17:11:56 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon *weapon) : _name(name), _weapon(weapon)
{
    return;
}

HumanB::HumanB(std::string name) : _name(name)
{
    return;
}

HumanB::~HumanB(void)
{
    return;
}

void        HumanB::setName(std::string input)
{
    this->_name = input;
    return;
}

void        HumanB::setWeapon(Weapon &input)
{
    this->_weapon = &input;
    return;
}

std::string HumanB::getName(void)
{
    return (this->_name);
}

Weapon*      HumanB::getWeapon(void)
{
    return (this->_weapon);
}

void        HumanB::attack(void)
{
    std::cout << GREEN << getName();
    std::cout << RESET << " attacks with their ";
    std::cout << RED << (*getWeapon()).getType();
    std::cout << RESET << std::endl;
    return;
}