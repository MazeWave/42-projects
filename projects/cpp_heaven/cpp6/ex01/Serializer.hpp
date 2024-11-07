/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/07 16:23:52 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************* STANDARD LIBRARIES ***************/
# pragma once
# include <iostream>
# include <string>
# include <stdint.h>
# include "Serializer.hpp"

/****************** FUNCTIONS *******************/
typedef struct Data
{
	unsigned int	i;
	double			d;
	char			c;
	std::string		str;
}		Data;

/******************* CLASSES ********************/
class   Serializer
{
	public:
	static	uintptr_t	serialize(Data* ptr);
	static	Data*		deserialize(uintptr_t raw);

	private:
	// Dummy constructor / destructor
	~Serializer(void) { return ; };
	Serializer(void) { return ; };
};

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