/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/10/23 23:55:20 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	Bureaucrat				Jobs = Bureaucrat("Steve Jobs", 1);
	Bureaucrat				Employee = Bureaucrat("Former Employee", 150);

	ShrubberyCreationForm	Moulberry = ShrubberyCreationForm("Gauntlet");
	RobotomyRequestForm		ClapTrap = RobotomyRequestForm("Borderlands");
	PresidentialPardonForm	Trump = PresidentialPardonForm("Trump");

	Jobs.signForm(Moulberry);	// Comment to create throw error in the try
	Jobs.signForm(ClapTrap);	// Comment to create throw error in the try
	Jobs.signForm(Trump);		// Comment to create throw error in the try

	// Will throw error
	Employee.signForm(Moulberry);
	Employee.signForm(ClapTrap);
	Employee.signForm(Trump);

	// If previous line commented, should get error and crash
	try
	{
		// Will suceed if Jobs signed the form
		Moulberry.execute(Jobs);
		ClapTrap.execute(Jobs);
		Trump.execute(Jobs);
		// Will throw an error no matter what
		Moulberry.execute(Employee);
		ClapTrap.execute(Employee);
		Trump.execute(Employee);
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}

	std::cout << CYAN << "--------------------------------------" << RESET << std::endl;

	Jobs.executeForm(Moulberry);
	Jobs.executeForm(ClapTrap);
	Jobs.executeForm(Trump);
	Employee.executeForm(Moulberry);
	Employee.executeForm(ClapTrap);
	Employee.executeForm(Trump);
	return (0);
}
