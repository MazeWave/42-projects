/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:44:20 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/29 02:47:08 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "Animal.hpp"

class   WrongAnimal
{
	protected:
	std::string	_type;

	public:
	WrongAnimal(void);
	~WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& input);

	WrongAnimal&		operator=(const WrongAnimal& input);
	std::string			getType(void) const;
	void				setType(std::string type);
	void				makeSound(void) const;
};

#endif