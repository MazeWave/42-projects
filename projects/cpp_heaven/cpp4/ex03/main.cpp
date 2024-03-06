/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/06 22:44:50 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

int		main(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	// {
	// 	IMateriaSource *src = new MateriaSource();

	// 	Ice ice1 = Ice();
	// 	Ice ice2 = ice1;	// = overload test

	// 	src->learnMateria(&ice1);
	// 	src->learnMateria(new Cure());
	// 	src->learnMateria(&ice2);
	// 	src->learnMateria(new Cure());
	// 	src->learnMateria(new Cure());
	// 	src->learnMateria(new Cure());
	// 	src->learnMateria(new Cure());

	// 	std::cout << "ice1 = " << ice1.getType() << std::endl;
	// 	std::cout << "ice2 = " << ice2.getType() << std::endl;

	// 	Character me = Character("me");

	// 	AMateria *tmp;
	// 	tmp = src->createMateria("ice");
	// 	me.equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me.equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me.equip(tmp);

	// 	ICharacter *bob = new Character("bob");

	// 	me.use(0, *bob);
	// 	me.use(1, *bob);
	// 	me.use(2, *bob);
	// 	me.use(3, *bob);
	// 	me.use(42, *bob);	//should return an error

	// 	Character meCopy = Character(me);

	// 	meCopy.use(0, *bob);

	// 	// Deep copy MateriaSource test
	// 	MateriaSource src1 = MateriaSource();
	// 	src1.learnMateria(src->createMateria("ice"));

	// 	// MateriaSource src2 = src1;
	// 	Character test = Character("test");
	// 	test.equip(src1.createMateria("ice"));
	// 	test.use(0, me);

	// 	delete bob;
	// 	delete src;
	// }
	return (0);
}
