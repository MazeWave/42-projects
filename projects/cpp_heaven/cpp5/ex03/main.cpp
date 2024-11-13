/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/13 17:10:43 by ldalmass         ###   ########.fr       */
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
	Intern	Stagiare;
	AForm	*Form;

	Form = Stagiare.makeForm("shrubbery creation", "garden");
	Form = Stagiare.makeForm("robotomy request", "Spot");
	Form = Stagiare.makeForm("presidential pardon", "Trump");
	Form = Stagiare.makeForm("form", "target");
	(void)Form;

	return (0);
}
