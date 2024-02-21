/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExerciceZeroOne.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:58:04 by ldalmass          #+#    #+#             */
/*   Updated: 2024/01/18 03:14:33 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXERCICEZEROONE_HPP
# define EXERCICEZEROONE_HPP

/************* STANDARD LIBRARIES ***************/
# include <iostream>
# include <sstream>

/****************** FUNCTIONS *******************/
void	clear_prompt(void);

/******************* CLASSES ********************/
class Contact
{
	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string secret;
	std::string number;

	public:
	Contact(void);
	~Contact(void);
	void add_entry(void);
	void remove_entry(void);
	void display_entry(void);
	void peek_entry(int index);
	std::string truncate_entry(std::string);
};

class PhoneBook
{
	private:
	Contact contacts[8];

	public:
	PhoneBook(void);
	~PhoneBook(void);
	void prompt(void);
	void search_contact(void);
	void add_contact(void);
	void exit_program(void);
};

/******************* COLORS *********************/
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define YELLOW "\033[33m"
# define BLACK "\033[30m"
# define WHITE "\033[37m"

#endif