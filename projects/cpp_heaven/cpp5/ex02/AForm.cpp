/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:48:35 by ldalmass          #+#    #+#             */
/*   Updated: 2024/10/21 17:54:13 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

AForm::~AForm(void)
{
	std::cout << MAGENTA << "Form default destructor called" << RESET << std::endl;
	return ;
}

AForm::AForm(void) : _name("42"), _exec_grade(42), _sign_grade(42), _signed(false)
{
	std::cout << MAGENTA << "Form default constructor called" << RESET << std::endl;
	return ;
}

AForm::AForm(std::string name, int exec_grade, int sign_grade) : _name(name), _exec_grade(exec_grade), _sign_grade(sign_grade)
{
	std::cout << MAGENTA << "Form constructor called" << RESET << std::endl;
	if (_exec_grade < 1 || _sign_grade < 1)
		throw AForm::GradeTooHighException();
	if(_exec_grade > 150 || _sign_grade > 150)
		throw AForm::GradeTooLowException();
	this->_signed = false;
	return ;
}

AForm::AForm(const AForm& input) : _name(input._name), _exec_grade(input._exec_grade), _sign_grade(input._sign_grade), _signed(input._signed)
{
	std::cout << MAGENTA << "Form copy constructor called" << RESET << std::endl;
	return ;
}

AForm& AForm::operator=(const AForm& input)
{
	std::cout << MAGENTA << "Form assignment overload operator called" << RESET << std::endl;
	this->_signed = input.getIsSigned();
	return (*this);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_exec_grade);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

void	AForm::beSigned(Bureaucrat& bureau)
{
	if (bureau.getGrade() > this->_sign_grade)
		throw GradeTooLowException();
	this->_signed = true;
	return ;
}

std::ostream&	operator<<(std::ostream &print, AForm const &form)
{
	print << form.getName() << ", Form Exec grade " << form.getExecGrade() << ", Form Sign grade " << form.getSignGrade() << ".";
	return print;
}