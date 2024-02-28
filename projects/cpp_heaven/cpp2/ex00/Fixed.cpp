/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:44:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/26 01:42:29 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
 
Fixed::Fixed(void)
{
    std::cout << RESET << "Default constructor called" << RESET << std::endl;
    this->_value = 0;
    return;
}

Fixed::~Fixed(void)
{
    std::cout << RESET << "Destructor called" << RESET << std::endl;
    return;
}

Fixed::Fixed(const Fixed& input)
{
    std::cout << RESET << "Copy constructor called" << RESET << std::endl;
	*this = input;
	return;
}

Fixed&	Fixed::operator=(const Fixed& input)
{
    std::cout << RESET << "Copy assignment called" << RESET << std::endl;
    this->_value = input.getRawBits();
    return (*this);
}

int     Fixed::getRawBits(void) const
{
    std::cout << RESET << "getRawBits member function called" << RESET << std::endl;
    return(this->_value);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << RESET << "setRawBits member function called" << RESET << std::endl;
    this->_value = raw;
    return;
}