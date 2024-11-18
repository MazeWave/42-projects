/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/16 14:55:18 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int		main(void)
{
	// Int array
	Array<int>	test1(42);
	for (unsigned short i = 0; i<test1.Size(); i++)
		test1[i] = i + 1;
	for (unsigned short i = 0; i<test1.Size(); i++)
	{
		if (i == test1.Size() - 1)
			std::cout << test1[i] << std::endl;
		else
			std::cout << test1[i] << ", ";
	}

	// 1 sized null array
	Array<void>	nulled(1);
	std::cout << nulled[0] << std::endl;

	// 4 sized null array
	Array<void>	nulleded(4);
	for (unsigned short i = 0; i<test1.Size(); i++)
		std::cout << nulleded[i] << std::endl;

	// std::string array
	Array<std::string>	test2(2);
	test2[0] = static_cast<const std::string>("Hello ");
	test2[1] = static_cast<const std::string>("World !");

	// const std::string array
	// Array<const std::string>	test3(test2);

	try
	{
		test1[42] = -1;
		std::cout << test1[42] << std::endl;
		test2[1] = static_cast<const std::string>("Friend !");
	}
	catch (std::exception &error) { std::cout << error.what() << std::endl; }
	return (0);
}
