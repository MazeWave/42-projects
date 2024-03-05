/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:45:54 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/05 17:57:33 by ldalmass         ###   ########.fr       */
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
	IMateriaSource(void);
	IMateriaSource(const IMateriaSource& input);
    ~IMateriaSource();

	MateriaSource&	operator=(const IMateriaSource& input);
    void			learnMateria(AMateria* m);
    AMateria*		createMateria(std::string const & type);
};

#endif
