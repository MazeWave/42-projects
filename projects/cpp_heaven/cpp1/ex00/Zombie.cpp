/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:17:47 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/16 17:20:50 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string input)
{
    set_name(input);
    return;
}

Zombie::~Zombie(void)
{
    std::cout << RESET << get_name() << " destroyed !" << RESET << std::endl;
    return;
}

void           Zombie::annouce(void)
{
    std::cout << RESET << get_name() << RESET;
    std::cout << RESET << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
    return;
}

void           Zombie::set_name(std::string input)
{
    this->_name = input;
    return;
}

std::string    Zombie::get_name(void)
{
    return(this->_name);
}
