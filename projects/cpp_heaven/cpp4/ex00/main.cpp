/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/11 16:51:58 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int		main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete j;
	delete i;
	delete meta;

	// OWN TESTS
	std::cout << "-------------" << RESET << std::endl;
	Animal	main;
	Cat		Baya(main);	//copy constructor
	std::cout << YELLOW << Baya.getType() << RESET << std::endl;
	Baya.makeSound();
	Dog		Pégase;
	std::cout << YELLOW << Pégase.getType() << RESET << std::endl;
	Pégase.makeSound();
	std::cout << "-------------" << RESET << std::endl;
	WrongAnimal	NotWanted;
	WrongCat	Garfield(NotWanted);	//copy constructor
	std::cout << YELLOW << Garfield.getType() << RESET << std::endl;
	Garfield.makeSound();
	std::cout << "-----END-----" << RESET << std::endl;
	return (0);
}
