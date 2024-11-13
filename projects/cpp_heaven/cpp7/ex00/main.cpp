/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/12 18:50:55 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int		main(void)
{
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
	std::cout << std::endl << GREEN << "Tests with (std::string)" << RESET << std::endl;
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
	return (0);
}
