/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/13 18:42:11 by ldalmass         ###   ########.fr       */
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
	~Array(void);
	Array(void);
	Array(unsigned int len);

	Array(const Array & input);
	Array&	operator=(const Array & input);

	unsigned int	Size(void);

	class	OutOfBandExcepetion : public std::exception
	{
		const char*	what() const throw()
		{
			return ("\033[31mOut of Band !\033[0m")
		}
	};
};

/****************** FUNCTIONS *******************/
template<typename T>
void	print_data(T & data) {std::cout << data << std::endl; return;}

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