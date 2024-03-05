/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/05 19:29:44 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "Main.hpp"

class	AMateria
{
	protected:
	std::string	_type;

	public:
	AMateria(void);
	AMateria(const std::string& type);
	AMateria(const AMateria& input);
	virtual	~AMateria();

	AMateria&			operator=(const AMateria& input);
	std::string const	&getType(void) const;
	void				setType(std::string type);
	virtual AMateria*	clone(void) const = 0;
	virtual	void		use(ICharacter& target);
};

#endif
