/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:48:24 by ldalmass          #+#    #+#             */
/*   Updated: 2024/10/21 16:02:29 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FORM_HPP
# define FORM_HPP

/************* STANDARD LIBRARIES ***************/
# pragma once
# include <iostream>
# include <string>
# include <exception>

/******************* CLASSES ********************/
class	Bureaucrat;

class   Form
{
	private:
	const std::string	_name;
	const int			_exec_grade;
	const int			_sign_grade;
	bool				_signed;

	public:
	Form(void);
	~Form(void);
	Form(std::string name, int exec_grade, int sign_grade);
	Form(const Form& input);

	Form&	operator=(const Form& input);

	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	bool		getIsSigned(void) const;
	std::string	getName(void) const;

	void		beSigned(Bureaucrat& bureau);

	class		GradeTooHighException: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("Form: Grade is too high");
		};
	};
	class		GradeTooLowException: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("Form: Grade is too low");
		};
	};
};

/****************** FUNCTIONS *******************/
std::ostream&	operator<<(std::ostream &print, Form const &form);

/******************* COLORS *********************/
# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"
# define CYAN		"\033[36m"
# define MAGENTA	"\033[35m"
# define YELLOW		"\033[33m"
# define BLACK		"\033[30m"
# define WHITE		"\033[37m"

#endif
