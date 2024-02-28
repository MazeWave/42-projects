/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/26 15:12:11 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap	Nabot("Nabot Sadique");

	Nabot.printStats();
	Nabot.attack("Garogot");
	Nabot.takeDamage(9);
	Nabot.beRepaired(9);
	Nabot.takeDamage(9);
	for (size_t i = 0; i < 9; i++)
		Nabot.beRepaired(1);
	Nabot.attack("Garogot");
	// for (size_t i = 0; i < 9; i++)
	// 	Nabot.beRepaired(1);
	
	return (0);
}
