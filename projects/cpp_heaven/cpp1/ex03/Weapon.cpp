/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:07:16 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/13 19:45:39 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : _type(NULL)
{
    return;
}

Weapon::Weapon(std::string input) : _type(input)
{
    return;
}

Weapon::~Weapon(void)
{
    return;
}

const std::string &Weapon::getType(void)
{
    return (this->_type);
}

void        Weapon::setType(std::string type)
{
    this->_type = type;
    return;
}
