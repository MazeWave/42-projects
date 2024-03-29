/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/11 18:29:27 by ldalmass         ###   ########.fr       */
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
	Animal *animals[4];
	std::cout << "-------------" << RESET << std::endl;
	std::cout << "Creating dogs" << RESET << std::endl;
	for (size_t i = 0; i < 2; i++)
	{
		std::cout << i << std::endl;
		animals[i] = new Dog();
	}
	std::cout << "-------------" << RESET << std::endl;
	std::cout << "Creating cats" << RESET << std::endl;
	for (size_t i = 2; i < 4; i++)
	{
		std::cout << i << std::endl;
		animals[i] = new Cat();
	}
	std::cout << "-------------" << RESET << std::endl;
	std::cout << "Deleting" << RESET << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << i << std::endl;
		delete animals[i];
	}
	std::cout << "-------------" << RESET << std::endl;
	std::cout << "Deep copy test" << RESET << std::endl;
	Cat	*cat = new Cat();
	const Cat	*cat2 = new Cat(*cat);	// Copy constructor
	std::cout << RED << cat->getType() << RESET << std::endl;
	std::cout << RED << cat2->getType() << RESET << std::endl;
	delete cat;
	delete cat2;
	std::cout << "-----END-----" << RESET << std::endl;
	return (0);
}
