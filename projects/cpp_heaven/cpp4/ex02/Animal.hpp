/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/29 21:41:55 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

/************* STANDARD LIBRARIES ***************/
# include <iostream>
# include <string>
# include "Brain.hpp"

/******************* CLASSES ********************/
class   Animal
{
	protected:
	std::string	_type;

	public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal& input);
	virtual	~Animal(void);

	Animal&				operator=(const Animal& input);
	std::string			getType(void) const;
	void				setType(std::string type);
	virtual	void		makeSound(void) const = 0;
};

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

#endif
