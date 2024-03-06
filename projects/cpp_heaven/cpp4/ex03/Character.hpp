/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:49:38 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/06 20:44:48 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Main.hpp"

class	Character: public ICharacter
{
	private:
	std::string	_name;
	AMateria	*_inventory[4];

	public:
	Character(const std::string& name);
	Character(const Character& input);
	virtual	~Character(void);

	Character&			operator=(const Character& input);
	std::string const &	getName(void) const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};

#endif