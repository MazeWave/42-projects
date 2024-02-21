/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/01 20:42:07 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ExerciceZeroOne.hpp"

int		main(void)
{
	PhoneBook 	nokia;	// instancie le répertoire Nokia 3310
	std::string	input;
	
	while(1)
	{
		nokia.prompt();
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			nokia.add_contact();
		else if (input.compare("SEARCH") == 0)
			nokia.search_contact();
		else if (input.compare("EXIT") == 0)
			return (0);
		else
			std::cout << RED << "Wrong input" << RESET << std::endl;
	}
	return (0);
}

void	clear_prompt(void)
{
	for (int i = 0; i < 128; i++)
		std::cout << std::endl;
	// std::cout << RED << "[CLEAR]" << RESET << std::endl;
	return;
}