/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/12/10 19:23:08 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int		main(void)
{
	// Own tests :
	std::cout << std::endl << YELLOW << "Own tests" << RESET << std::endl;
	std::cout << GREEN << "Tests with (int)" << RESET << std::endl;
	{
		int	a = 42;
		int	b = -42;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << min<int>(a, b) << std::endl;
		std::cout << max<int>(a, b) << std::endl;
		swap<int>(a, b);
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	}
	std::cout << std::endl << GREEN << "Tests with (float)" << RESET << std::endl;
	{
		float	a = 42.69;
		float	b = -42.69;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << min<float>(a, b) << std::endl;
		std::cout << max<float>(a, b) << std::endl;
		swap<float>(a, b);
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	}
	std::cout << std::endl << GREEN << "Tests with (char)" << RESET << std::endl;
	{
		char	a = 'a';
		char	b = 'z';

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << min<char>(a, b) << std::endl;
		std::cout << max<char>(a, b) << std::endl;
		swap<char>(a, b);
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	}
	std::cout << std::endl << GREEN << "Tests with (std::string) (complex type)" << RESET << std::endl;
	{
		std::string	a = "tetsetest";
		std::string	b = "tetsetestZ";

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << ::min<std::string>(a, b) << std::endl;
		std::cout << ::max<std::string>(a, b) << std::endl;
		::swap<std::string>(a, b);
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	}

	// Provided test from the subject :
	std::cout << std::endl << YELLOW << "Provided test from the subject" << RESET << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	// Provided test from the corretion :
	std::cout << std::endl << YELLOW << "Provided test from the correction" << RESET << std::endl;
	{
		Awesome a(2), b(4);

		swap(a, b);
		std::cout << a << " " << b << std::endl;
		std::cout << max(a, b) << std::endl;
		std::cout << min(a, b) << std::endl;
	}


	return (0);
}
