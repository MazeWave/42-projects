/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/29 22:46:48 by ldalmass         ###   ########.fr       */
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
	for (size_t i = 0; i < 2; i++)
	{
		std::cout << i << std::endl;
		animals[i] = new Dog();
	}
	std::cout << "-------------" << RESET << std::endl;
	for (size_t i = 2; i < 4; i++)
	{
		std::cout << i << std::endl;
		animals[i] = new Dog();
	}
	std::cout << "-------------" << RESET << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << i << std::endl;
		delete animals[i];
	}
	std::cout << "-----END-----" << RESET << std::endl;
	return (0);
}
