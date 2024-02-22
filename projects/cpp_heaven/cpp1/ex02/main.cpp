/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/13 17:30:51 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(void)
{
	// Notre phrase
	std::string	string = "HI THIS IS BRAIN";

	// Pointeur qui pointe sur l'addresse de brain
	std::string	*stringPTR = &string;

	// String qui stocke l'adresse de brain
	std::string	&stringREF = string;

	// Print les adresses
	std::cout << "Adresse de string :	" << &string << std::endl;
	std::cout << "Adresse de stringPTR :	" << &stringPTR << std::endl;
	std::cout << "Adresse de stringREF :	" << &stringREF << std::endl;

	// Print le contenu des varaibles
	std::cout << "Contenu de string :	" << string << std::endl;
	std::cout << "Contenu de stringPTR :	" << stringPTR << std::endl;
	std::cout << "Contenu de stringREF :	" << stringREF << std::endl;

	return (0);
}
