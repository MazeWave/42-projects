/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:04:03 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/06 18:30:25 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "Main.hpp"

class	Ice: public AMateria
{
	public:
	Ice(void);
	Ice(const Ice& input);
	virtual	~Ice(void);

	AMateria*	clone(void) const;
	void		use(ICharacter& target);
	Ice&		operator=(const Ice& input);
};

#endif