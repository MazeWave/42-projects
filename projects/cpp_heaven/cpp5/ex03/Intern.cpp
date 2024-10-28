/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:10:00 by ldalmass          #+#    #+#             */
/*   Updated: 2024/10/28 18:34:12 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::~Intern(void)
{
	return ;
}

Intern::Intern(void)
{
	return ;
}

Intern::Intern(const Intern& input)
{
	(void)input;
	return ;
}

Intern&	Intern::operator=(const Intern& input)
{
	(void)input;
	return (*this);
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	AForm	*createdForm = NULL;

	std::string	type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	form = UNKNOWN_FORM;

	for (int i = 0; i < 3; i++)
		if (formName == type[i])
			form = i;
	switch (form)
	{
		case SHRUBBERY:
			createdForm = new ShrubberyCreationForm(target);
			break;
		case ROBOTOMY:
			createdForm = new RobotomyRequestForm(target);
			break;
		case PRESIDENTIAL:
			createdForm = new PresidentialPardonForm(target);
			break;
		case UNKNOWN_FORM:
			std::cout << RED << "Requested form does not exist !" << std::endl << YELLOW << "Form types: shrubbery creation, robotomy request, presidential pardon." << RESET << std::endl;
			return (NULL);
	}
	std::cout <<GREEN << "Intern creates " << createdForm->getName() << RESET << std::endl;
	return (createdForm);
}
