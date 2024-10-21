/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:48:35 by ldalmass          #+#    #+#             */
/*   Updated: 2024/10/21 15:59:51 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::~Form(void)
{
	std::cout << MAGENTA << "Form default destructor called" << RESET << std::endl;
	return ;
}

Form::Form(void) : _name("42"), _exec_grade(42), _sign_grade(42), _signed(false)
{
	std::cout << MAGENTA << "Form default constructor called" << RESET << std::endl;
	return ;
}

Form::Form(std::string name, int exec_grade, int sign_grade) : _name(name), _exec_grade(exec_grade), _sign_grade(sign_grade)
{
	std::cout << MAGENTA << "Form constructor called" << RESET << std::endl;
	if (_exec_grade < 1 || _sign_grade < 1)
		throw Form::GradeTooHighException();
	if(_exec_grade > 150 || _sign_grade > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
	return ;
}

Form::Form(const Form& input) : _name(input._name), _exec_grade(input._exec_grade), _sign_grade(input._sign_grade), _signed(input._signed)
{
	std::cout << MAGENTA << "Form copy constructor called" << RESET << std::endl;
	return ;
}

Form& Form::operator=(const Form& input)
{
	std::cout << MAGENTA << "Form assignment overload operator called" << RESET << std::endl;
	this->_signed = input.getIsSigned();
	return (*this);
}

bool	Form::getIsSigned(void) const
{
	return (this->_signed);
}

int	Form::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade(void) const
{
	return (this->_exec_grade);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

void	Form::beSigned(Bureaucrat& bureau)
{
	if (bureau.getGrade() > this->_sign_grade)
		throw GradeTooLowException();
	this->_signed = true;
	return ;
}

std::ostream&	operator<<(std::ostream &print, Form const &form)
{
	print << form.getName() << ", Form Exec grade " << form.getExecGrade() << ", Form Sign grade " << form.getSignGrade() << ".";
	return print;
}