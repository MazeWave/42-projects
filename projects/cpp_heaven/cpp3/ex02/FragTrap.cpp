/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:02:10 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/28 02:51:12 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << MAGENTA << "FragTrap Default constructor " << RESET << std::endl;
	return;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << MAGENTA << "FragTrap Constructor " << name << RESET << std::endl;
	this->_name = name;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << MAGENTA << "FragTrap Desctructor " << this->_name << RESET << std::endl;
	return;
}

FragTrap::FragTrap(const ClapTrap& input)
{
	std::cout << MAGENTA << "FragTrap Copy Constructor " << this->_name << RESET << std::endl;
	ClapTrap::operator=(input);
	return;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << RESET << "Hey there, 🌞 You've done a goodjob ! 🤌" << RESET << std::endl;
	return;
}