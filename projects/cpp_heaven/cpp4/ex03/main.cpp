/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/07 17:54:12 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

int		main(void)
{
	// IMateriaSource* src = new MateriaSource();

	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter* me = new Character("me");
	// AMateria* tmp;

	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	
	// ICharacter* bob = new Character("bob");

	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;

	{
		IMateriaSource *src = new MateriaSource();

		std::cout << GREEN << "test1" << RESET << std::endl;
		Ice *ice1 = new Ice();
		Ice ice2 = *ice1;	// = overload test

		src->learnMateria(ice1);
		src->learnMateria(new Cure());
		src->learnMateria(ice2.clone());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());	//return error
		src->learnMateria(new Cure());	//return error
		src->learnMateria(new Cure());	//return error

		std::cout << GREEN << "test2" << RESET << std::endl;
		std::cout << "ice1 = " << ice1->getType() << std::endl;
		std::cout << "ice2 = " << ice2.getType() << std::endl;

		Character me = Character("me");

		std::cout << GREEN << "test3" << RESET << std::endl;
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me.equip(tmp);
		tmp = src->createMateria("cure");
		me.equip(tmp);
		tmp = src->createMateria("cure");
		me.equip(tmp);

		ICharacter *bob = new Character("bob");

		std::cout << GREEN << "test4" << RESET << std::endl;
		me.use(0, *bob);
		me.use(1, *bob);
		me.use(2, *bob);
		me.use(3, *bob);
		me.use(42, *bob);	//should return an error

		Character meCopy = Character(me);

		std::cout << "HEEEEEEEEEEEEERRRRRRRRREEEEEEEEEEEEE\n";
		me.use(3, *bob);
		std::cout << GREEN << "test5" << RESET << std::endl;
		meCopy.use(0, *bob);

		std::cout << GREEN << "test6" << RESET << std::endl;
		// Deep copy MateriaSource test
		MateriaSource src1 = MateriaSource();
		src1.learnMateria(src->createMateria("ice"));
		
		std::cout << "HEEEEEEEEEEEEERRRRRRRRREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\n";
		me.use(3, *bob);
		
		std::cout << GREEN << "test7" << RESET << std::endl;
		Character *test = new Character("test");
		std::cout << GREEN << "test8" << RESET << std::endl;
		test->equip(src1.createMateria("ice"));
		std::cout << GREEN << "test9" << RESET << std::endl;
		//test.use(0, me);
		std::cout << GREEN << "test10" << RESET << std::endl;
			
		std::cout << "HEEEEEEEEEEeeeeeeeeeeeeeeeeeeeeeeeeeeeEEERRRRRRRRREEEEEEEEEEEEE\n";
		me.use(3, *bob);

		delete bob;
		std::cout << GREEN << "test11" << RESET << std::endl;
		delete src;
		std::cout << GREEN << "test12" << RESET << std::endl;
		std::cout << GREEN << "test13" << RESET << std::endl;

	}

	return (0);
}
