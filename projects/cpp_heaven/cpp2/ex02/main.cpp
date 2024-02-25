/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/25 19:01:40 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int		main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}

std::ostream&	operator<<(std::ostream& output, const Fixed& input)
{
	output << input.toFloat();
	return (output);
}

	// {
	// 	Fixed a(69.42f);
	// 	Fixed b(42.69f);
	// 	const Fixed d(2.42f);
	// 	const Fixed e(42.69f);
	// 	Fixed c;
	// 	std::cout << YELLOW << "----- Min/Max ------" << RESET << std::endl;
	// 	std::cout << RESET << "a = " << a << RESET << std::endl;
	// 	std::cout << RESET << "b = " << b << RESET << std::endl;
	// 	std::cout << RESET << "Min = " << c.min(a,b) << RESET << std::endl;
	// 	std::cout << RESET << "Max = " << c.max(a,b) << RESET << std::endl;
	// 	std::cout << RESET << "Min = " << Fixed::min(d,e) << RESET << std::endl;
	// 	std::cout << RESET << "Max = " << Fixed::max(d,e) << RESET << std::endl;

	// 	std::cout << YELLOW << "----- Pre/Post incremetation/decrementation ------" << RESET << std::endl;
	// 	std::cout << RESET << "b-- = " << b-- << RESET << std::endl;
	// 	std::cout << RESET << "--b = " << --b << RESET << std::endl;
	// 	std::cout << RESET << "b++ = " << b++ << RESET << std::endl;
	// 	std::cout << RESET << "++b = " << ++b << RESET << std::endl;

	// 	std::cout << YELLOW << "----- Arithmetic operators ------" << RESET << std::endl;
	// 	std::cout << RESET << "b + 100 = " << b + 100 << RESET << std::endl;
	// 	std::cout << RESET << "b - 100 = " << b - 100 << RESET << std::endl;
	// 	std::cout << RESET << "b * 100 = " << b * 100 << RESET << std::endl;
	// 	std::cout << RESET << "b / 100 = " << b / 100 << RESET << std::endl;

	// 	std::cout << YELLOW << "----- Boolean operators ------" << RESET << std::endl;
	// 	std::cout << RESET << "a = " << a << RESET << std::endl;
	// 	std::cout << RESET << "b = " << b << RESET << std::endl;
	// 	std::cout << RESET << "b <= a : " << (bool)(b <= a) << RESET << std::endl;
	// 	std::cout << RESET << "b >= a : " << (bool)(b >= a) << RESET << std::endl;
	// 	std::cout << RESET << "b < a : " << (bool)(b < a) << RESET << std::endl;
	// 	std::cout << RESET << "b > a : " << (bool)(b > a) << RESET << std::endl;

	// 	std::cout << GREEN << "Swaping a and b values" << RESET << std::endl;
	// 	Fixed	temp;
	// 	temp = b;
	// 	b = a;
	// 	a = temp;
	// 	std::cout << RESET << "a = " << a << RESET << std::endl;
	// 	std::cout << RESET << "b = " << b << RESET << std::endl;
	// 	std::cout << RESET << "b <= a : " << (bool)(b <= a) << RESET << std::endl;
	// 	std::cout << RESET << "b >= a : " << (bool)(b >= a) << RESET << std::endl;
	// 	std::cout << RESET << "b < a : " << (bool)(b < a) << RESET << std::endl;
	// 	std::cout << RESET << "b > a : " << (bool)(b > a) << RESET << std::endl;
	// 	std::cout << GREEN << "Comparaisons" << RESET << std::endl;
	// 	std::cout << RESET << "b == a : " << (bool)(b == a) << RESET << std::endl;
	// 	std::cout << RESET << "b != a : " << (bool)(b != a) << RESET << std::endl;
	// 	std::cout << GREEN << "Setting a value to b value" << RESET << std::endl;
	// 	a = b;
	// 	std::cout << RESET << "b == a : " << (bool)(b == a) << RESET << std::endl;
	// 	std::cout << RESET << "b != a : " << (bool)(b != a) << RESET << std::endl;
	// }