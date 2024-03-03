/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:05:25 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/29 21:24:11 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class	Brain
{
	public:
	Brain(void);
	Brain(const Brain& imput);
	~Brain(void);

	Brain&			operator=(const Brain& input);
	std::string		ideas[100];

};

#endif