/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/16 17:26:03 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main(int argc, char **argv)
{
	if (argc != 1)
	{
		// Créer notre horde de zombie
		int	number = std::atoi(argv[1]);
		Zombie	*horde = zombieHorde(number, "Frankenstein");

		// Annonce notre horde de zombie
		for (int i = 0; i < number; i++)
			horde[i].annouce();

		// On delete tout les zombie alloués dans la heap
		delete [] horde;
	}
	else
	{
		// Créer notre horde de zombie
		Zombie	*horde = zombieHorde(4, "Frankenstein");

		// Annonce notre horde de zombie
		for (int i = 0; i < 4; i++)
			horde[i].annouce();

		// On delete tout les zombie alloués dans la heap
		delete [] horde;
	}
	
	return (0);
}
