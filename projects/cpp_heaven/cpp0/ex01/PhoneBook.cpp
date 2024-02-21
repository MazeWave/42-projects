/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:28:15 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/01 20:53:36 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ExerciceZeroOne.hpp"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "Destructor of" << YELLOW << " PhoneBook called !" << RESET << std::endl;
	return;
}

void	PhoneBook::prompt(void)
{
	clear_prompt();
	std::cout << GREEN << "/////////   Nokia 3310 Phonebook  /////////" << RESET << std::endl;
	std::cout << YELLOW << "ADD   " << RESET << " : Create a new contact" << std::endl;
	std::cout << YELLOW << "SEARCH" << RESET << " : Display all contacts" << std::endl;
	std::cout << YELLOW << "EXIT  " << RESET << " : Exit Nokia 3310 Phonebook" << std::endl;
	std::cout << GREEN << "Choice : " << RESET;
	return;
}

void	PhoneBook::search_contact(void)
{
	std::string	input;
	int	i = -1;

	// Print contacts
	clear_prompt();
	std::cout << RESET << "┌──────────┬──────────┬──────────┬──────────┐" << RESET << std::endl;
	std::cout << RESET << "│" << MAGENTA << "     INDEX" << RESET << "│" << MAGENTA << "FIRST NAME" << RESET << "│" << MAGENTA << " LAST NAME" << RESET << "│" << MAGENTA << "  NICKNAME" << RESET << "│" << std::endl;
	std::cout << RESET << "├──────────┼──────────┼──────────┼──────────┤" << RESET << std::endl;
	while(++i < 8)
		this->contacts[i].peek_entry(i);
	std::cout << RESET << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;

	// Ask the user to see a contatc detail
	std::cout << YELLOW << "Press ENTER or any key to go back" << RESET << std::endl;
	std::cout << YELLOW << "Enter a valid index to see a contact details" << RESET << std::endl;
	std::cout << GREEN << "Choice : " << RESET;

	//Prompt to see a particular contact
	std::getline(std::cin, input);
	std::stringstream atoi(input);
	if (input.empty() == true)
		return;
	i = 0;
	atoi >> i;
	if (i >= 1 && i <= 8)
		this->contacts[i - 1].display_entry();
	else
		std::cout << RED << "Your number is out ouf range !" << RESET << std::endl;
	return;
}

void	PhoneBook::add_contact(void)
{
	static unsigned int	i = 0;

	std::cout << YELLOW << "PhoneBook::add_contact called !" << RESET << std::endl;
	contacts[i % 8].remove_entry();
	contacts[i % 8].add_entry();
	i++;
	clear_prompt();
	return;
}

void	PhoneBook::exit_program(void)
{
	std::cout << YELLOW << "PhoneBook::exit_program called !" << RESET << std::endl;
	return;
}
