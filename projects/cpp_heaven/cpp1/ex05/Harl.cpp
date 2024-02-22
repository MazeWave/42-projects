/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:44:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/16 16:12:19 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    return;
}

Harl::~Harl(void)
{
    return;
}

void    Harl::complain(std::string level)
{
    // Debug print
    // std::cout << MAGENTA << "User input : " << level << RESET << std::endl;

    // Create our pointer to member function Harll::debug/info/warning/error with a reference to it
    std::string	choice[4] =                                 {"DEBUG", "INFO", "WARNING", "ERROR"};
    void        (Harl::*ptr_to_member_function[4])(void) =  {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

		// Run through choice index until user input match choice's index
		for (int i = 0; i < 4; i++)
		{
			if (choice[i] == level)
                (this->*ptr_to_member_function[i])();
		}
    return;
}

void    Harl::debug(void)
{
    std::cout << GREEN << "[DEBUG] : " << RESET;
    std::cout << RESET << "net.minecraft.client.eval.player.pos = [-156, 64, 1296]" << RESET << std::endl;
    return;
}

void    Harl::info(void)
{
    std::cout << BLUE << "[INFO] : " << RESET;
    std::cout << RESET << "net.minecraft.client.version = [22.457.267a]" << RESET << std::endl;
    return;
}

void    Harl::warning(void)
{
    std::cout << YELLOW << "[WARNING] : " << RESET;
    std::cout << RESET << "net.minecraft.server.integrated.packet.class[166:43] : UDP[00000761437978] PACKET LOSS WITH CLIENT" << RESET << std::endl;
    return;
}

void    Harl::error(void)
{
    std::cout << RED << "[ERROR] : " << RESET;
    std::cout << RESET << "net.minecraft.client.render.regionClassifier.class[342:90] : Undefined behavior: value -1 underflow for unsigned float at address <0x33b4fa67>" << RESET << std::endl;
    return;
}
