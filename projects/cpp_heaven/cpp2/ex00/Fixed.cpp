/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:44:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/21 20:35:45 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
 
Fixed::Fixed(void)
{
    std::cout << RESET << "Default constructor called" << RESET << std::endl;
    this->_fixed_point = 0;
    return;
}

Fixed::~Fixed(void)
{
    std::cout << RESET << "Default destructor called" << RESET << std::endl;
    return;
}

Fixed::Fixed(const Fixed& input)
{
    std::cout << RESET << "Copy constructor called" << RESET << std::endl;
	this->operator=(input);
}

Fixed&	Fixed::operator=(const Fixed& input)
{
    std::cout << RESET << "Copy assignment called" << RESET << std::endl;
    this->_fixed_point = input.getRawBits();
    return (*this);
}

int     Fixed::getRawBits(void) const
{
    std::cout << RESET << "getRawBits member function called" << RESET << std::endl;
    return(this->_raw_bit);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << RESET << "setRawBits member function called" << RESET << std::endl;
    this->_fixed_point = raw;
    return;
}