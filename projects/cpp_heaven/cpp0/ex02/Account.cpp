/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:18:46 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/05 18:11:54 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = this->getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	return;
}

Account::~Account(void)
{
	std::cout << "Account destroyed" << std::endl;
	return;
}
