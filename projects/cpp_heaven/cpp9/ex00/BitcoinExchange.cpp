/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:57:23 by ldalmass          #+#    #+#             */
/*   Updated: 2025/01/29 22:18:19 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(const char *path)
{
	std::ifstream	file(path);
	std::string		line;

	// Create the database exchange rate in our std::map this->_data
	try { getDataBase(); }
	catch (std::exception &error) { std::cout << error.what() << std::endl; return ; }
	printData();
	

	// Check if the input file is open
	if (!file.is_open())
		throw CannotReadFileException();

	// Check rate for each line of input file
	std::getline(file, line);
	printData();
	while (std::getline(file, line))
		getExchangeRate(line);
	printData();
	// std::cout << BLUE << readValue("date,exchange_rate") << std::endl;
	file.close();
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &input)
{
	*this = input;
	return ;
}

// BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &input)
// {
// 	// this->_data = input.getData();
// 	return (*this);
// }

std::string trimLine(const std::string str)
{
	std::string::const_iterator start = str.begin();
	std::string::const_iterator end = str.end();

	// Remove spaces at start
	while (start != str.end() && std::isspace(*start))
		++start;
	// Remove spaces at end
	do --end;
	while (end != start && std::isspace(*end));
	// std::cout << "Trimmed Line : " << std::string(start, end + 1) << std::endl;
	return (std::string(start, end + 1));
}

double			BitcoinExchange::readValue(const std::string value)
{
	std::string	str;
	double		result = -1.0;

	str = ::trimLine(value);

	if (str.size() <= 10)
		return (-1.0);

    std::string::const_reverse_iterator r_start = str.rbegin();
    std::string::const_reverse_iterator r_end = str.rend();

	while (r_start != r_end && (std::isdigit(*r_start) || *r_start == '.' || *r_start == '-'))
		++r_start;
	if (r_start == str.rbegin())
		return (-1.0);

	std::string::const_iterator	start = r_start.base();
	std::string::const_iterator	end = str.end();

	str = std::string(start, end);
	if (str.empty())
		return (-1.0);
	result = std::atof(str.c_str());

	// std::cout << RED << str.c_str() << RESET << std::endl;
	// std::cout << RED << result << RESET << std::endl;

	return (result);
}

unsigned long	BitcoinExchange::readDate(const std::string date)
{
	unsigned long	result;
	std::string		str = ::trimLine(date);

	if (str.size() < 10)
		return (-1);

	result = std::atol((str.substr(0,4) + str.substr(5,2) + str.substr(8,2)).c_str());
	// result = std::strtol(str.replace(str.find('-'), 1, ""), NULL, 10);
	std::cout << result << std::endl;
	return (result);
}

bool	BitcoinExchange::checkValue(const double value)
{
	if (value < 0.0)
		return (std::cout << RED ERR_NEG_NUMBER RESET << std::endl, false);
	
	if (value > 1000)
		return (std::cout << RED ERR_TOO_LARGE RESET << std::endl, false);

	return (true);
}

bool	BitcoinExchange::checkDate(const std::string date)
{
	std::string	str = ::trimLine(date);
	// Check line's lenght and '-' presence
	if (str.size() < 10)
		return (false);
	if (str[4] != '-' || str[7] != '-')
		return (false);

	// Date format : YYYY-MM-DD : 2020-02-29
	unsigned short	year =	std::atol((str.substr(0,4)).c_str());
	unsigned short	month =	std::atol((str.substr(5,2)).c_str());
	unsigned short	day =	std::atol((str.substr(8,2)).c_str());
	
	bool			bissextile = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int				daysInMonth[12] = { 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	daysInMonth[1] = bissextile ? 29 : 28;

	if (DEBUG != 0)
	{
		std::cout << "Date : " <<  year << "/" << month << "/" << day<< " " ;
		std::cout << BLUE << "Day : " <<  day << " | " << "Max Day : " << daysInMonth[1] << " | " << RESET ;
		std::cout << YELLOW << (bissextile ? "année bissextile | " : "") << RESET;
	}

	if (year > 9999 || month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1])
		return (false);
	return (true);
}

void	BitcoinExchange::getDataBase(void)
{
	std::ifstream	file("./data.csv");
	std::string		line;

	// Check if the file is open
	if (!file.is_open())
		throw CannotReadFileException();

	// Check header
	std::getline(file, line);
	if (line != "date,exchange_rate")
	{
		file.close();
		throw WrongHeaderExcepetion();
	}

	// Read lines one by one until EOF and put informations in this->_data
	while (std::getline(file, line))
	{
		this->_data[readDate(line)] = readValue(line);
		std::cout << line << std::endl;
	}

	file.close();
	return ;
}

void	BitcoinExchange::printData(void)
{
	std::map<unsigned long, double>::const_iterator	start = this->_data.begin();
	std::map<unsigned long, double>::const_iterator	end = this->_data.end();

	std::cout << "------------------" << std::endl;
	while (start != end)
	{
		std::cout << MAGENTA << "Key : " << start->first << " | Value : " << std::setprecision(7) << start->second << RESET << std::endl;
		++start;
	}
	return ;
}

unsigned long	BitcoinExchange::findDateInDataBase(const unsigned long date)
{
	unsigned long	result;

	std::map<unsigned long, double>::const_iterator	start = this->_data.begin();
	std::map<unsigned long, double>::const_iterator	end = this->_data.end();

	result = start->first;
	while (start != end)
	{
		std::cout << YELLOW << result << " < " << date << RESET << std::endl;
		std::cout << YELLOW << "Current date " << start->first << RESET << std::endl;
		
		++start;
		if (result < date)
			break;
		result = start->first;
	}

	std::cout << CYAN << "Nearest date : " << result << RESET << std::endl;

	return (result);
}

double	BitcoinExchange::getRate(const unsigned long date)
{
	std::cout << GREEN << "DB Key : " << date << " | " << "DB Rate : " << this->_data[date] << RESET << std::endl;
	return (this->_data[date]);
}

void	BitcoinExchange::getExchangeRate(const std::string raw)
{
	unsigned long	wanted_date = readDate(raw);
	// std::cout << YELLOW << wanted_date << RESET << std::endl;
	unsigned long	nearest_date = findDateInDataBase(wanted_date);
	double			value = readValue(raw);
	double			rate = getRate(nearest_date);

	if (::trimLine(raw).size() < 10)
		return ;
	if (checkValue(value * rate) && checkValue(value) && checkValue(rate))
		std::cout << ::trimLine(raw).substr(0, 10) << " => " << value << " => " << value * rate << std::endl;
	return ;
}