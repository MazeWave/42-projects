/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 01:12:16 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/29 02:26:19 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

/******************* CLASSES ********************/
class	Cat : public Animal
{
	public:
	Cat(void);
	Cat(const Animal& input);
	~Cat(void);

	Cat&	operator=(const Cat& input);
	void	makeSound(void) const;
};

#endif
