/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/11 19:22:28 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int		main(void)
{
	// Animal	test;			// Can't instanciate
	// Animal test2 = Dog();	// because class is abstract
	Animal *animals[4];
	for (size_t i = 0; i < 2; i++)
		animals[i] = new Dog();
	std::cout << "-------------" << RESET << std::endl;
	for (size_t i = 2; i < 4; i++)
		animals[i] = new Cat();
	std::cout << "-------------" << RESET << std::endl;
	for (size_t i = 0; i < 4; i++)
		delete animals[i];
	std::cout << "-----END-----" << RESET << std::endl;
	return (0);
}
