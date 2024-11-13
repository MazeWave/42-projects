/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:11:30 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/13 16:37:38 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << MAGENTA << "Default RobotomyRequestForm destructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 5, 25), _target("Target")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 5, 25), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& input) : AForm(input), _target(input._target)
{
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& input)
{
	if (this != &input)
		this->_target = input._target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw UnsignedFormException();

	std::cout << GREEN << this->_target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
	return ;
}