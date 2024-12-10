/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/12/11 00:55:21 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************* STANDARD LIBRARIES ***************/
# pragma once
# include <iostream>
# include <string>
# include <exception>

/******************* CLASSES ********************/

template<typename T>
class	Array
{
	private:
	unsigned int	_len;
	T*				_array;

	public:
	~Array(void)
	{
		if (this->_len == 0)
			return ;
		else
			delete[] this->_array;
		return ;
	}
	Array(void) : _len(0), _array(NULL) { return; }
	Array(unsigned int len) : _len(len), _array(new T[len])
	{
		this->_len = len;
		this->_array = new T[len];
		for (unsigned int i = 0; i < this->_len; i++)
			this->_array[i] = T();	// Use default type T provided
		return ;
	}
	Array(Array<T> const & input) : _len(input._len), _array(input._len > 0 ? new T[input._len] : T())
	{
		for (unsigned int i = 0; i < _len; i++)
			_array[i] = input._array[i];
	}

	unsigned int	size(void) { return (this->_len); }

	Array&	operator=(Array<T> const & input)
	{
		if (this->_len > 0 && this->_array)
			delete[] this->_array;
		if (input._len == 0)
			return (Array<T>());
		this->_len = input._len;
		this->_array = new T[this->_len];
		for (unsigned int i = 0; i < this->_len; i++)
			this->_array[i] = input._array[i];

		return (*this);
	}
	T&			operator[](unsigned int pos)
	{
		if (pos >= this->_len)
			throw OutOfBandExcepetion();
		return (this->_array[pos]);
	}
	const T&	operator[](unsigned int pos) const
	{
		if (pos >= this->_len)
			throw OutOfBandExcepetion();
		return (this->_array[pos]);
	}

	class	OutOfBandExcepetion : public std::exception
	{
		virtual const char*	what() const throw()
		{
			return ("\033[31mOut of Band !\033[0m");
		}
	};
};

/****************** FUNCTIONS *******************/

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