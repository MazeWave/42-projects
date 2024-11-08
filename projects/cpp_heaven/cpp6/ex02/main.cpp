/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/08 19:45:21 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int		main(void)
{
	// Generate A, B or C class
	Base*	test = Base::generate();

	// Test child class with a pointer
	Base::indentify(test);

	// Test child class with a reference
	Base::indentify(*test);

	// Test with an invalid class
	Base::indentify(NULL);

	delete test;
	return (0);
}
