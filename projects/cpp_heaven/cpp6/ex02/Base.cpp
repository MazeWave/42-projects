/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:18:40 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/19 18:28:37 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *	Base::generate(void)
{
	srand(time(NULL));
	unsigned short	index = rand() % 3;
	switch (index)
	{
		case 0:
			if (DEBUG != 0)
				std::cout << YELLOW << "Generated:\tA" << RESET << std::endl;
			return (new A());
		case 1:
			if (DEBUG != 0)
				std::cout << YELLOW << "Generated:\tB" << RESET << std::endl;
			return (new B());
		case 2:
			if (DEBUG != 0)
				std::cout << YELLOW << "Generated:\tC" << RESET << std::endl;
			return (new C());
		default:
			return (std::cout << RED << "Generation Error" << RESET << std::endl, static_cast<Base *>(NULL));
	}
	return (NULL);
}

void	Base::indentify(Base* p)
{
	A*	testA = dynamic_cast<A*>(p);
	B*	testB = dynamic_cast<B*>(p);
	C*	testC = dynamic_cast<C*>(p);

	try
	{
		if (testA != NULL)
			return (std::cout << GREEN << "p:\t\tA" << RESET << std::endl, static_cast<void>(NULL));
		if (testB != NULL)
			return (std::cout << GREEN << "p:\t\tB" << RESET << std::endl, static_cast<void>(NULL));
		if (testC != NULL)
			return (std::cout << GREEN << "p:\t\tC" << RESET << std::endl, static_cast<void>(NULL));
		else
			throw notTheSameParentClass();
	}
	catch ( std::exception &error ) { std::cout << error.what() << std::endl; }
	return ;
}

void	Base::indentify(Base& p)
{
	try
	{
		try
		{
			(void)dynamic_cast<A&>(p);
			return (std::cout << GREEN << "p:\t\tA" << RESET << std::endl, static_cast<void>(NULL));
		}
		catch ( std::exception& ) {  }
		try
		{
			(void)dynamic_cast<B&>(p);
			return (std::cout << GREEN << "p:\t\tB" << RESET << std::endl, static_cast<void>(NULL));
		}
		catch ( std::exception& ) {  }
		try
		{
			(void)dynamic_cast<C&>(p);
			return (std::cout << GREEN << "p:\t\tC" << RESET << std::endl, static_cast<void>(NULL));
		}
		catch ( std::exception& ) {  }

		throw notTheSameParentClass();
	
	}
	catch (std::exception &error) { std::cout << error.what() << std::endl; }
	return ;
}
