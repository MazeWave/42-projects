/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:11:30 by ldalmass          #+#    #+#             */
/*   Updated: 2024/10/23 17:24:55 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << MAGENTA << "Default ShrubberyCreationForm destructor called" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 137, 145), _target("Target")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 137, 145), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& input) : AForm(input), _target(input._target)
{
	return ;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& input)
{
	*this = input;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw UnsignedFormException();

	std::fstream	file;
	
	file.open((this->_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	if (file.is_open())
	{
		file << "                                                 . " << std::endl;
		file << "                                      .         ;  " << std::endl;
		file << "         .              .              ;%     ;;   " << std::endl;
		file << "           ,           ,                :;%  %;   " << std::endl;
		file << "            :         ;                   :;%;'     .,   " << std::endl;
		file << "   ,.        %;     %;            ;        %;'    " << std::endl;
		file << "     ;       ;%;  %%;        ,     %;    ;%;    ,%'"  << std::endl;
		file << "      %;       %;%;      ,  ;       %;  ;%;   ,%;' "<< std::endl;
		file << "       ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
		file << "        `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
		file << "         `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
		file << "            `:%;.  :;bd%;          %;@%;'" << std::endl;
		file << "              `@%:.  :;%.         ;@@%;'   " << std::endl;
		file << "                `@%.  `;@%.      ;@@%;         " << std::endl;
		file << "                  `@%%. `@%%    ;@@%;        " << std::endl;
		file << "                    ;@%. :@%%  %@@%;       " << std::endl;
		file << "                      %@bd%%%bd%%:;     " << std::endl;
		file << "                        #@%%%%%:;;" << std::endl;
		file << "                        %@@%%%::;" << std::endl;
		file << "                        %@@@%(o);  . '         " << std::endl;
		file << "                        %@@@o%;:(.,'         " << std::endl;
		file << "                    `.. %@@@o%::;         " << std::endl;
		file << "                       `)@@@o%::;         " << std::endl;
		file << "                        %@@(o)::;        " << std::endl;
		file << "                       .%@@@@%::;         "<< std::endl;
		file << "                       ;%@@@@%::;.          " << std::endl;
		file << "                      ;%@@@@%%:;;;. " << std::endl;
		file << "                  ...;%@@@@@%%:;;;;,..    Gilo97 " << std::endl;
		file.close();
	}
	else
		std::cout << RED << "Failed to open file : " << this->_target << "_shrubbery" << RESET << std::endl;
	return ;
}