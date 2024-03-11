/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:10:45 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/11 17:44:59 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	private:
	Brain	*_brain;

	public:
	Dog(void);
	Dog(const Dog& input);
	~Dog(void);

	Dog&	operator=(const Dog& input);
	void	makeSound(void);
};

#endif
