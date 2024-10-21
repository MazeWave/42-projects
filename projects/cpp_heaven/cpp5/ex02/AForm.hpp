/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:48:24 by ldalmass          #+#    #+#             */
/*   Updated: 2024/10/21 17:57:20 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  AFORM_HPP
# define AFORM_HPP

/************* STANDARD LIBRARIES ***************/
# pragma once
# include <iostream>
# include <string>
# include <exception>

/******************* CLASSES ********************/
class	Bureaucrat;

class   AForm
{
	private:
	const std::string	_name;
	const int			_exec_grade;
	const int			_sign_grade;
	bool				_signed;

	public:
	AForm(void);
	~AForm(void);
	AForm(std::string name, int exec_grade, int sign_grade);
	AForm(const AForm& input);

	AForm&	operator=(const AForm& input);

	int				getSignGrade(void) const;
	int				getExecGrade(void) const;
	bool			getIsSigned(void) const;
	std::string		getName(void) const;

	void			beSigned(Bureaucrat& bureau);
	virtual void	do_things(Bureaucrat const &bureau) const = 0;

	class		GradeTooHighException: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("AForm: Grade is too high");
		};
	};
	class		GradeTooLowException: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("AForm: Grade is too low");
		};
	};
};

/****************** FUNCTIONS *******************/
std::ostream&	operator<<(std::ostream &print, AForm const &form);

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
