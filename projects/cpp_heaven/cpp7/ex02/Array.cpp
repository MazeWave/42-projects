/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:42:21 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/13 18:51:21 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

Array::~Array(void)
{
	if (this->_len == 0)
		return ;
	else
		delete[] this->_array;
	return ;
}

Array::Array(void) : _len(static_cast<unsigned int>(0)), _array(NULL)
{
	return ;
}

Array::Array(unsigned int len)
{
	this->_len = len;
	this->_array = new[len] T;
	return ;
}

Array&	Array::Array(const & Array input)
{
	
	return (this);
}

unsigned int	Array::Size(void)
{
	return (this->_len);
}