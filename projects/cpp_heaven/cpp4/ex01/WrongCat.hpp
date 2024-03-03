/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:44:18 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/29 02:49:35 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class   WrongCat : public WrongAnimal
{
	public:
	WrongCat(void);
	~WrongCat(void);
	WrongCat(const WrongAnimal& input);

	WrongCat&		operator=(const WrongCat& input);
	void			makeSound(void) const;
};

#endif