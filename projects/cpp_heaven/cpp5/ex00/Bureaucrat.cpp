/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:18:40 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/13 15:40:38 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(void)
{
	std::cout << MAGENTA << "Bureaucrat default destructor called" << RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(void) : _name("42"), _grade(42)
{
	std::cout << MAGENTA << "Bureaucrat default constructor called" << RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << MAGENTA << "Bureaucrat constructor called" << RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& input)
{
	std::cout << MAGENTA << "Bureaucrat copy constructor called" << RESET << std::endl;
	*this = input;
	return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& input)
{
	std::cout << MAGENTA << "Bureaucrat assignment overload operator called" << RESET << std::endl;
	this->_grade = input.getGrade();
	return (*this);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	return ;
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

std::ostream&	operator<<(std::ostream &print, Bureaucrat const &bureaucrat)
{
	print << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return print;
}