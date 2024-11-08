/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/08 20:09:44 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************* STANDARD LIBRARIES ***************/
# pragma once
# include <iostream>
# include <cmath>
# include <exception>

/******************* CLASSES ********************/

class   Base
{
	public:
	virtual ~Base(void) { return ; };
	static Base *	generate(void);
	static void			indentify(Base* p);
	static void			indentify(Base& p);


	class notTheSameParentClass: public std::exception
	{
		const char*	what() const throw ()
		{
			return ("\033[31mBase: Child class do not herit from Base !\033[0m");
		}
	};
};

class	A : public Base {};

class	B : public Base {};

class	C : public Base {};

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