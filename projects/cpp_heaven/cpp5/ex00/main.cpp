/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/13 15:46:04 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{
	// Grade too high scenario
	Bureaucrat	Wozniak = Bureaucrat("Steve Wozniak", 1);
	Bureaucrat	Jobs = Wozniak;
	std::cout << GREEN << Wozniak << RESET << std::endl;
	std::cout << GREEN << Jobs << RESET << std::endl;

	// Grade too low scenario
	Bureaucrat	NewEmploye = Bureaucrat("Nouvel Employé", 150);
	Bureaucrat	Stagiaire = NewEmploye;
	std::cout << GREEN << NewEmploye << RESET << std::endl;
	std::cout << GREEN << Stagiaire << RESET << std::endl;

	// ostream overload test
	Bureaucrat test1;
	std::cout << test1 << std::endl;	// ostream overload test

	// Tests
	try
	{
		// Jobs.incrementGrade();
		// Stagiaire.decrementGrade();
		// Bureaucrat toohigh = Bureaucrat("toohigh", 0);
		// Bureaucrat toohigh = Bureaucrat("toohigh", -1);
		// Bureaucrat toolow = Bureaucrat("toolow", 151);
	}
	catch (std::exception& error)
	{
		std::cout << error.what() << std::endl;
	}

	return (0);
}
