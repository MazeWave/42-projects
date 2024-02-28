/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/27 15:20:17 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	ScavTrap	Jack("Beau Jack");
	// ClapTrap	Nabot("Nabot Sadique");
	// ScavTrap	Jack(Nabot);
	Jack.guardGate();
	Jack.guardGate();
	Jack.printStats();
	for (short i = 0; i < 49; i++)
		Jack.attack("TrapClap");
	Jack.takeDamage(30);
	Jack.beRepaired(10);
	Jack.attack("TrapClap");
	return (0);
}
