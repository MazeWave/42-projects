/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/13 17:11:43 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************* STANDARD LIBRARIES ***************/
# include <iostream>
# include <string>
# include <exception>

/******************* CLASSES ********************/
class   Bureaucrat
{
	private:
	const std::string	_name;
	int					_grade;

	public:
	Bureaucrat(void);
	~Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& input);

	Bureaucrat&	operator=(const Bureaucrat& input);

	void		incrementGrade(void);
	void		decrementGrade(void);

	int			getGrade(void) const;
	std::string	getName(void) const;

	class		GradeTooHighException: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("Grade is too high, you can't have a grade higher than 1");
		};
	};
	class		GradeTooLowException: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("Grade is too low, you can't have a grade lower than 150");
		};
	};
};

/****************** FUNCTIONS *******************/
std::ostream&	operator<<(std::ostream &print, Bureaucrat const &bureaucrat);

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
