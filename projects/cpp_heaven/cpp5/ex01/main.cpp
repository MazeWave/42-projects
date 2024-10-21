/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/10/21 16:19:54 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	Bureaucrat	Jobs = Bureaucrat("Steve Jobs", 1);
	Form		iPhone = Form("iPhone", 42, 42);

	std::cout << iPhone.getIsSigned() << std::endl;
	std::cout << Jobs << std::endl;
	std::cout << iPhone << std::endl;

	// signForm tests
	Jobs.signForm(iPhone);		// should sign the first ever and greatest iPhone prototype
	std::cout << iPhone.getIsSigned() << std::endl;

	Bureaucrat	Employee = Bureaucrat("Former Employee", 99);

	std::cout << Employee << std::endl;
	Employee.signForm(iPhone);	// should throw error

	Form		Falcon = Form("Falcon Heavy", 1, 1);
	std::cout << Falcon << std::endl;
	std::cout << Falcon.getIsSigned() << std::endl;

	// beSigned tests
	Bureaucrat	Musk = Bureaucrat("Elon Musk", 1);
	std::cout << Musk << std::endl;
	try
	{
		Falcon.beSigned(Musk);	// should work
		std::cout << Falcon.getIsSigned() << std::endl;
		Falcon.beSigned(Employee);	// should throw error
		std::cout << Falcon << std::endl;
	}
	catch (std::exception& error)
	{
		std::cout << error.what() << std::endl;
	}
	return (0);
}
