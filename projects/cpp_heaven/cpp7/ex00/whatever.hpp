/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/12 17:12:20 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************* STANDARD LIBRARIES ***************/
# pragma once
# include <iostream>
# include <string>
# include <exception>

/******************* CLASSES ********************/

template<typename T>
T const &	min(T const & a,T const & b)
{
	return (a < b ? a : b);
}

template<typename T>
T const &	max(T const & a,T const & b)
{
	return (a > b ? a : b);
}

template< typename T>
void	swap(T & a,T & b)
{
	T temp	= a;	// c saves a

	a = b;
	b = temp;
	return ;
}

/****************** FUNCTIONS *******************/

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

# define DEBUG 0