/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/03/11 16:30:49 by ldalmass         ###   ########.fr       */
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
	// return 0;

	{
		std::cout << CYAN << "┌───────── PART 1 ──────────┐" << RESET << std::endl;
		std::cout << CYAN << "│      Materia Source       │" << RESET << std::endl;
		std::cout << CYAN << "└───────────────────────────┘" << RESET << std::endl;
		{
			// With Ice
			std::cout << GREEN << "With Ice" << RESET << std::endl;
			AMateria		*ice = new Ice();
			IMateriaSource	*src = new MateriaSource();
			src->learnMateria(ice);
			src->learnMateria(ice);
			src->learnMateria(ice);
			src->learnMateria(ice);
			src->learnMateria(ice);		// Should return error
			delete ice;
			delete src;
		}
		{
			// With Cure
			std::cout << GREEN << "With Cure" << RESET << std::endl;
			AMateria		*cure = new Cure();
			IMateriaSource	*src = new MateriaSource();
			src->learnMateria(cure);
			src->learnMateria(cure);
			src->learnMateria(cure);
			src->learnMateria(cure);
			src->learnMateria(cure);	// Should return error
			delete cure;
			delete src;
		}
		{
			// Error test
			std::cout << GREEN << "Other error test" << RESET << std::endl;
			AMateria		*ice = new Ice();
			IMateriaSource	*src = new MateriaSource();
			src->learnMateria(NULL);	// Should return error
			src->createMateria("cure");	// Should return error
			delete ice;
			delete src;
		}
		std::cout << CYAN << "┌───────── PART 2 ──────────┐" << RESET << std::endl;
		std::cout << CYAN << "│        Characters         │" << RESET << std::endl;
		std::cout << CYAN << "└───────────────────────────┘" << RESET << std::endl;
		{
			// Test use() member function
			ICharacter	*bob = new Character("bob");
			AMateria	*ice = new Ice();
			AMateria	*cure = new Cure();
			bob->equip(ice);
			bob->equip(cure);
			bob->use(0, *bob);
			bob->use(1, *bob);
			bob->use(2, *bob);	// Should return warning
			bob->use(4, *bob);	// Should return error
			delete ice;
			delete cure;
			delete bob;
		}
		{
			// Test equip() member function
			ICharacter	*bob = new Character("bob");
			AMateria	*ice = new Ice();
			bob->equip(ice);
			bob->equip(ice);
			bob->equip(ice);
			bob->equip(ice);
			bob->equip(ice);	// Should return error
			delete ice;
			delete bob;
		}
		{
			// Test unequip() member function
			ICharacter	*bob = new Character("bob");
			AMateria	*ice = new Ice();
			bob->equip(ice);
			bob->unequip(0);
			bob->unequip(0);	// Should return warning
			bob->unequip(1);	// Should return warning
			bob->unequip(4);	// Should return error
			delete ice;
			delete bob;
		}
	}
	return (0);
}
