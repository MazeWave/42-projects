/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/22 16:31:02 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/************* STANDARD LIBRARIES ***************/
# include <iostream>
# include <cstdlib>
# include <string>
# include <fstream>
# include <cmath>

/******************* CLASSES ********************/
class   Fixed
{
    private:
    int                 _value;
    static const int    _raw_bit = 8;

    public:
    Fixed(void);	// Default constructor
    ~Fixed(void);	// Default destructor

    Fixed(const Fixed& input);				// Copy constructor
    Fixed&	operator=(const Fixed& input);	// Assignment operator overload

	Fixed(const int itof);					// Int to Float constructor 
	Fixed(const float ftoi);				// Float to Int constructor

	int		toInt(void) const;				// Float to Int converter
	float	toFloat(void) const;			// Int to Float converter

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

/****************** FUNCTIONS *******************/
std::ostream&	operator<<(std::ostream& output, const Fixed& input);	// Output stream overload operator

/******************* COLORS *********************/
# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"
# define CYAN		"\033[36m"
# define MAGENTA	"\033[35m"
# define YELLOW		"\033[33m"
# define BLACK		"\033[30m"
# define WHITE		"\033[37m"

#endif
