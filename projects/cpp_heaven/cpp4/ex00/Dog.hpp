/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:10:45 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/29 02:26:26 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
	Dog(void);
	Dog(const Animal& input);
	~Dog(void);

	Dog&	operator=(const Dog& input);
	void	makeSound(void);
};

#endif
