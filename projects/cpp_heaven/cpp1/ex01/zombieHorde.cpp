/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:53:39 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/16 17:26:05 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	// Créer N zombie
	Zombie*	horde = new Zombie[N];

	// Ajoute le nom des zombie,
	// on ne peut plus passer d'input "name" dans notre 
	// constructeur si on veut allouer un tableau de zombie
	// dans la stack, d'où cette pratique de getters et setters
	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return (horde);
}
