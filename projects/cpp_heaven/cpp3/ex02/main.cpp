/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/28 02:52:20 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int		main(void)
{
	FragTrap	Jack("Beau Jack");
	// ClapTrap	Nabot("Nabot Sadique");
	// FragTrap	Jack(Nabot);
	Jack.printStats();
	for (short i = 0; i < 99; i++)
		Jack.attack("TrapClap");
	Jack.takeDamage(30);
	Jack.printStats();
	Jack.beRepaired(10);
	Jack.printStats();
	Jack.attack("TrapClap");
	Jack.highFivesGuys();
	return (0);
}
