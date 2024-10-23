/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:11:30 by ldalmass          #+#    #+#             */
/*   Updated: 2024/10/23 21:01:39 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << MAGENTA << "Default RobotomyRequestForm destructor called" << RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 45, 72), _target("Target")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 45, 72), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& input) : AForm(input), _target(input._target)
{
	return ;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& input)
{
	*this = input;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw UnsignedFormException();

	std::cout << YELLOW << "Vzzzzzzzzzzzzzz, Brrrrrrrrrrrrrrrr, Vzzzz Vzzzz" << RESET << std::endl;

	srand(time(NULL));
	if (rand() % 2 == 1)
		std::cout << GREEN << this->_target << " has successfully been Robotomized" << RESET << std::endl;
	else
		std::cout << RED << this->_target << " Robotomization procedure failed. Aborting." << RESET << std::endl;
	return ;
}