/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/16 17:20:44 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int			main(void)
{
	// teste la classe par défaut et alloue un zombie dans la stack
	Zombie	number_one("Number one");	// instancie le zombie Number one
	number_one.annouce();

	// instancie un autre zombie dans la stack au travers d'une fonction,
	// mais cette fonction ne nous donne pas ce zombie, on ne peut pas s'en servir :/
	randomChump("Random zombie");

	// Créer un zombie dans la heap au travers d'une fonction,
	// celui-ci nous est return et on peut donc l'utiliser partout
	Zombie	*heap_zombie = newZombie("Super zombie");
	heap_zombie->annouce();

	// On n'oublie pas de désallouer notre super zombie dans la heap
	delete (heap_zombie);
	return (0);
}
