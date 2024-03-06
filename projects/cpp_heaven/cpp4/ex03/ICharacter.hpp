/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:26:46 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/06 19:05:49 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "Main.hpp"

// Declaration fix :
class	AMateria;
/* Without this class AMateria it would not compile and result like this :
ICharacter.hpp:23:28: error: ‘AMateria’ has not been declared
   23 |         virtual void equip(AMateria* m) = 0;
      |                            ^~~~~~~~
*/

class	ICharacter
{
	public:
	virtual ~ICharacter(void) {}
	virtual std::string const & getName(void) const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif