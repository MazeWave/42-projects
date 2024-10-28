/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/10/28 18:59:39 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int		main(void)
{
	Intern Stagiare;
	AForm	*Form;

	Form = Stagiare.makeForm("shrubbery creation", "garden");
	Form = Stagiare.makeForm("robotomy request", "Spot");
	Form = Stagiare.makeForm("presidential pardon", "Trump");
	Form = Stagiare.makeForm("form", "target");
	(void)Form;
	return (0);
}
