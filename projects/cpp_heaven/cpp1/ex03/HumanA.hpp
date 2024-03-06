/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:06:45 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/13 20:04:32 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

/************* STANDARD LIBRARIES ***************/
# include <iostream>
# include <cstdlib>
# include <string>
# include "Weapon.hpp"

/******************* CLASSES ********************/

class   HumanA
{
    private:
    std::string     _name;
    Weapon          &_weapon;

    public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void);
    void            setName(std::string input);
    void            setWeapon(Weapon input);
    std::string     getName(void);
    Weapon          getWeapon(void);
    void            attack(void);
};

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