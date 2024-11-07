/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/07 16:23:30 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int		main(void)
{
	Data	test1 = 
	{
		42,
		0.21,
		'N',
		"Hello Cpp"
	};

	// Base Data structure print (ground truth)
	std::cout << CYAN << "test1 :" << RESET << std::endl;
	std::cout << test1.i << std::endl;
	std::cout << test1.d << std::endl;
	std::cout << test1.c << std::endl;
	std::cout << test1.str << std::endl;

	// Serialized data (converting our struct to a uintptr_t with all of its data)
	uintptr_t serialized = Serializer::serialize(&test1);
	// Unserialized data (converting back to Data* structure with hopefully all of our data unchagned)
	Data* test2 = Serializer::deserialize(serialized);

	// After processing print (Compare it to ground truth)
	std::cout << RED << "test2 :" << RESET << std::endl;
	std::cout << test2->i << std::endl;
	std::cout << test2->d << std::endl;
	std::cout << test2->c << std::endl;
	std::cout << test2->str << std::endl;

	return (0);
}
