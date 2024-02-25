/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:44:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/25 19:02:07 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
 
Fixed::Fixed(void)
{
    // std::cout << RESET << "Default constructor called" << RESET << std::endl;
    this->_value = 0;
    return;
}

Fixed::~Fixed(void)
{
    // std::cout << RESET << "Default destructor called" << RESET << std::endl;
    return;
}

Fixed::Fixed(const Fixed& input)
{
    // std::cout << RESET << "Copy constructor called" << RESET << std::endl;
	*this = input;
	return;
}

Fixed&	Fixed::operator=(const Fixed& input)
{
    // std::cout << RESET << "Copy assignment called" << RESET << std::endl;
    this->_value = input.getRawBits();
    return (*this);
}

Fixed::Fixed(const int itof)
{
	// std::cout << RESET << "Int constructor called" << RESET << std::endl;
	this->_value = roundf(itof * (1 << this->_raw_bit));
	return;
}

Fixed::Fixed(const float ftoi)
{
	// std::cout << RESET << "Float constructor called" << RESET << std::endl;
	this->_value = roundf(ftoi * (float)(1 << this->_raw_bit));
	return;
}

int		Fixed::toInt(void) const
{
	return (this->_value / (1 << this->_raw_bit));
}

float		Fixed::toFloat(void) const
{
	return (this->_value / (float)(1 << this->_raw_bit));
}

int     Fixed::getRawBits(void) const
{
    // std::cout << RESET << "getRawBits member function called" << RESET << std::endl;
    return(this->_value);
}

void    Fixed::setRawBits(int const raw)
{
    // std::cout << RESET << "setRawBits member function called" << RESET << std::endl;
    this->_value = raw;
    return;
}

/* Ex02 Operator overload member functions */

// Min and max muber functions
Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);	// Ternary form
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

const	Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

const	Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

// Boolean  comparaison overload
bool	Fixed::operator==(const Fixed& input) const
{
	return (this->toFloat() == input.toFloat());
}

bool	Fixed::operator!=(const Fixed& input) const
{
	return (this->toFloat() != input.toFloat());
}

bool	Fixed::operator<(const Fixed& input) const
{
	return (this->toFloat() < input.toFloat());
}

bool	Fixed::operator<=(const Fixed& input) const
{
	return (this->toFloat() <= input.toFloat());
}

bool	Fixed::operator>(const Fixed& input) const
{
	return (this->toFloat() > input.toFloat());
}

bool	Fixed::operator>=(const Fixed& input) const
{
	return (this->toFloat() >= input.toFloat());
}

// Arithmetic overload
Fixed	Fixed::operator+(const Fixed& input) const
{
	return (Fixed(this->toFloat() + input.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& input) const
{
	return (Fixed(this->toFloat() - input.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& input) const
{
	return (Fixed(this->toFloat() * input.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& input) const
{
	if (input == 0)
	{
		std::cout << RED << "Error : can't divide by 0 !" << RESET << std::endl;
		exit (1);
	}
	return (Fixed(this->toFloat() + input.toFloat()));
}

// Pre Incrementation/Decramentation
Fixed&	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

// Post Incrementation/Decramentation

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->_value++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	this->_value--;
	return (temp);
}
