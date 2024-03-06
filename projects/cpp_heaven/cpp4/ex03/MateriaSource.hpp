/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:45:54 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/06 19:50:45 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "Main.hpp"

class	MateriaSource : public IMateriaSource
{
    private:
	AMateria *_learned_materias[4];

	public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& input);
    ~MateriaSource(void);

	MateriaSource&	operator=(const MateriaSource& input);
    void			learnMateria(AMateria* m);
    AMateria*		createMateria(std::string const & type);
};

#endif
