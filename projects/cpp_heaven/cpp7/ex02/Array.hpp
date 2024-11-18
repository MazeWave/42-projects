/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/15 20:35:10 by ldalmass         ###   ########.fr       */
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
	Array(void) : _len(static_cast<unsigned int>(0)), _array(NULL) { return; }
	Array(unsigned int len)
	{
		this->_len = len;
		this->_array = new T[len];
		for (unsigned int i = 0; i < this->_len; i++)
			this->_array[i] = NULL;
		return ;
	}
	Array(Array<T> const & input)
	{
		if (input._len == 0)
			this = Array<T>();
		else
		{
			this->_len = input._len;
			this->_array = new T[this->_len];
			for (unsigned int i = 0; i < this->_len; i++)
				this->_array[i] = input._array[i];
		}
	}
	Array&	operator=(Array<T> const & input)
	{
		if (this._len == 0)
			return (Array<T>());
		this->_len = input._len;
		this->_array = new T[this->_len];
		for (unsigned int i = 0; i < this->_len; i++)
			this->_array[i] = input._array[i];
		return (*this);
	}

	unsigned int	Size(void) { return (this->_len); }

	T&	operator[](unsigned int pos)
	{
		if (pos >= this->_len)
			throw OutOfBandExcepetion();
		return (this->_array[pos]);
	}
	
	T const &	operator[](unsigned int pos) const	// Alt for constant _array
	{
		if (pos >= this->_len)
			throw OutOfBandExcepetion();
		return (this->_array[pos]);
	}

	class	OutOfBandExcepetion : public std::exception
	{
		const char*	what() const throw()
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