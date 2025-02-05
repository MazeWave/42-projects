/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2025/02/05 15:05:51 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/************* STANDARD LIBRARIES ***************/
# include <iostream>
# include <iomanip>
# include <fstream>		// for std::ifstream
# include <string>
# include <exception>
# include <algorithm>	// for rand() / srand() / std::generate()

# include <map>			// for std::map

# include <cstdlib>

/******************* CLASSES ********************/
class	BitcoinExchange
{
	private:
	/* Database : (unsigned long -> date | double -> btc value) */
	std::map<unsigned long, double>	_data;

	public:
	BitcoinExchange(void)			{ return ; };
	~BitcoinExchange(void);
	BitcoinExchange(const char *path);
	BitcoinExchange(const BitcoinExchange &input);

	BitcoinExchange&	operator=(const BitcoinExchange &input);

	static std::string		trimLine(const std::string str);
	static double			readValue(const std::string value);
	static unsigned long	readDate(const std::string date);
	static bool				checkDate(const std::string date);
	static bool				checkValue(const double value);

	void					getExchangeRate(const std::string raw);
	void					getDataBase(void);
	void					printData(void);
	unsigned long			findDateInDataBase(const unsigned long date);
	double					getRate(const unsigned long date);

	class		CannotReadFileException: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("\033[31mThe input file could not be opened !\033[0m");
		};
	};
	class		WrongHeaderExcepetion: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("\033[31mThe header must match : \033[37mdate,exchange_rate\033[0m");
		};
	};
};

/****************** FUNCTIONS *******************/
# define ERR_BAD_DATE	"Error: bad input => "
# define ERR_NEG_NUMBER	"Error: not a positive number."
# define ERR_TOO_LARGE	"Error: too large a number."
# define ERR_INCOMPLATE_DATE	"Error: incomplete date."

/******************* COLORS *********************/
# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"
# define CYAN		"\033[36m"
# define MAGENTA	"\033[35m"
# define YELLOW		"\033[33m"
# define BLACK		"\033[30m"
# define WHITE		"\033[37m"

# define DEBUG 0