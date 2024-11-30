/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:44:05 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/30 01:01:32 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(size_t len)
{
	this->_len = len;
	return ;
}

void	Span::addNumber(int number)
{
	if (this->_data.size() < this->_len)
		this->_data.push_back(number);
	else
		throw outOfRangeException();
	return ;
}

Span::Span(const Span& input)
{
	// std::cout << MAGENTA << "Span copy constructor " << input.getType() << RESET << std::endl;
	*this = input;
	return;
}

Span& Span::operator=(const Span& input)
{
	// Assignment operator overload
	this->_len = input._len;
	this->_data = input._data;
	return (*this);
}

int	Span::longestSpan(void)
{
	unsigned int	longest = 0;
	// unsigned int	current;
	
	// Initials tests
	if (this->_data.size() <= 1)
		throw cannotFindLongestSpan();

	// Black magic
	std::vector<int>	sortedData(this->_data);
	std::sort(sortedData.begin(), sortedData.end());

	// Calculations
	longest = sortedData[sortedData.size() -1] - sortedData[0];
	std::cout << "✅⏫ Longest span : " << longest << std::endl;
	return (longest);
}

int	Span::shortestSpan(void)
{
	unsigned int	current;
	unsigned int	shortest;
	
	// Initials tests
	if (this->_data.size() <= 1)
		throw cannotFindShortestSpan();

	// Black magic
	std::vector<int>	sortedData(this->_data);
	std::sort(sortedData.begin(), sortedData.end());

	// Calculations
	shortest = sortedData[1] - sortedData[0];
	for (size_t i = 1; i < sortedData.size(); i++)
	{
		current = sortedData[i] - sortedData[i - 1];
		if (current < shortest)
			shortest = current;
	}

	std::cout << "✅⏬ Shortest span : " << shortest << std::endl;
	return (shortest);
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t	distance = static_cast<size_t>(std::distance(begin, end));

	if (distance + this->_data.size() > this->_len)
		throw outOfRangeException();
	this->_data.insert(this->_data.end(), begin, end);

	return ;
}

unsigned int	Span::dist(int a, int b)
{
	unsigned int	distance = std::numeric_limits<unsigned int>::max();

	int	max = a > b ? a : b;
	int min = a < b ? a : b;

	if (DEBUG != 0)
	{
		std::cout << CYAN << "max = " << max << RESET << std::endl;
		std::cout << CYAN << "min = " << min << RESET << std::endl;
		std::cout << MAGENTA << "Distance between " << a << " and " << b << RESET << " : " << distance << std::endl;
	}

	distance = abs(max - min);
	return (distance);
}

void	Span::printNumbers(void)
{
	std::vector<int>::iterator	biter = this->_data.begin();
	std::vector<int>::iterator	eiter = this->_data.end();

	while (biter != eiter)
	{
		std::cout << *biter << std::endl;
		biter++;
	}
	return ;
}

int	Span::getLen(void)
{
	return (this->_len);
}