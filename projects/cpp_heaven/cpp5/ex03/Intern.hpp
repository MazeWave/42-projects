/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:10:20 by ldalmass          #+#    #+#             */
/*   Updated: 2024/10/28 18:30:43 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  INTERN_HPP
# define INTERN_HPP

/************* STANDARD LIBRARIES ***************/
# pragma once
# include <iostream>
# include <string>
# include <exception>
# include <fstream>

# include "AForm.hpp"

/******************* CLASSES ********************/

class   Intern
{
	public:
	~Intern(void);
	Intern(void);
	Intern(const Intern& input);
	Intern&	operator=(const Intern& input);

	AForm	*makeForm(std::string formName, std::string target);
};

/****************** FUNCTIONS *******************/
enum formType
{
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENTIAL,
	UNKNOWN_FORM
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

#endif
