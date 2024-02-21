/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:28:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/01 20:54:27 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ExerciceZeroOne.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	// std::cout << "Destructor of" << YELLOW << " Contact called !" << RESET << std::endl;
	return;
}

void	Contact::add_entry(void)
{
	std::string input;

	input.clear();
	while (input.empty() == 1)
	{
		std::cout << RESET << "First name : " << RESET << std::endl;
		std::getline(std::cin, input);
		this->first_name = input;
	}
	input.clear();
	while (input.empty() == 1)
	{
		std::cout << RESET << "Last name : " << RESET << std::endl;
		std::getline(std::cin, input);
		this->last_name = input;
	}
	input.clear();
	while (input.empty() == 1)
	{
		std::cout << RESET << "Nickname : " << RESET << std::endl;
		std::getline(std::cin, input);
		this->nickname = input;
	}
	input.clear();
	while (input.empty() == 1)
	{
		std::cout << RESET << "Number : " << RESET << std::endl;
		std::getline(std::cin, input);
		this->secret = input;
	}
	input.clear();
	while (input.empty() == 1)
	{
		std::cout << RESET << "Secret : " << RESET << std::endl;
		std::getline(std::cin, input);
		this->number = input;
	}
	return;
}

void	Contact::remove_entry(void)
{
	first_name.clear();
	last_name.clear();
	nickname.clear();
	secret.clear();
	number.clear();
	return;
}

std::string Contact::truncate_entry(std::string input)
{
	if (input.length() > 10)
		return (input.substr(0, 9) + ".");
	else if (input.length() == 10)
		return (input);
	else
	{
		int	i = -1;
		std::string	spaces;

		while (++i < (10 - (int)(input.length())))
			spaces = spaces.append(" ");
		return (spaces + input);
	}
}

void	Contact::peek_entry(int index)
{
	// Setup truncated/formed variables
	std::string first_name;
	std::string last_name;
	std::string nickname;

	// Fill in the gaps and truncate if needed
	first_name = truncate_entry(this->first_name);
	last_name = truncate_entry(this->last_name);
	nickname = truncate_entry(this->nickname);

	// Print the result
	std::cout << RESET << "│";
	std::cout << RESET << "         " << index + 1;
	std::cout << RESET << "│";
	std::cout << RESET << first_name;
	std::cout << RESET << "│";
	std::cout << RESET << last_name;
	std::cout << RESET << "│";
	std::cout << RESET << nickname;
	std::cout << RESET << "│";
	std::cout << std::endl;
	return;
}

void	Contact::display_entry(void)
{
	// Check if the contact exist
	if (first_name.empty() == true)
	{
		std::cout << RED << "This contact doesn't exist !" << RESET << std::endl;
		return;
	}
	else
		clear_prompt();

	// Print the contact details
	std::cout << RESET << "First name : " << this->first_name << std::endl;
	std::cout << RESET << "Nickname   : " << this->nickname << std::endl;
	std::cout << RESET << "Last name  : " << this->last_name << std::endl;
	std::cout << RESET << "Number     : " << this->number << std::endl;
	std::cout << RESET << "Secret     : " << this->secret << std::endl;

	// Wait for user interaction to leave the contact displayed
	std::cout << std::endl << GREEN << "Press ENTER or any key to go back : " << RESET;
	std::string input;
	std::getline(std::cin, input);
	if (input.empty() == true || input.empty() == false)
		return;
}
