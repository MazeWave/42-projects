/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:04:00 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/06 18:31:35 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "Main.hpp"

class	Cure: public AMateria
{
	public:
	Cure(void);
	Cure(const Cure& input);
	virtual	~Cure(void);

	AMateria*	clone(void) const;
	void		use(ICharacter& target);
	Cure&		operator=(const Cure& input);
};

#endif