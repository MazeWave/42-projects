/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:11:19 by ldalmass          #+#    #+#             */
/*   Updated: 2024/10/23 20:25:53 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

/************* STANDARD LIBRARIES ***************/
# pragma once
# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include <cstdlib>

# include "AForm.hpp"

/******************* CLASSES ********************/

class   RobotomyRequestForm : public AForm
{
	private:
	std::string	_target;

	public:
	~RobotomyRequestForm(void);
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& input);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& input);

	void	execute(Bureaucrat const &executor) const;
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
