/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:58:04 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/16 17:27:38 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

/************* STANDARD LIBRARIES ***************/
# include <iostream>
# include <cstdlib>
# include <string>

/******************* CLASSES ********************/
class Zombie
{
	private:
	std::string _name;

	public:
	Zombie(void);
	~Zombie(void);
	std::string	get_name(void);
	void		set_name(std::string input);
	void		annouce(void);
};

/****************** FUNCTIONS *******************/
Zombie*		zombieHorde(int N, std::string name);

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

#endif