/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/12/11 01:52:44 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

static int	get_random(void)
{
	return (rand() - std::numeric_limits<int>::max() / 2);
}

int		main(void)
{
	std::cout << YELLOW << "Own tests :" << RESET << std::endl;
	
	{
		MutantStack<int>	mstack;
		std::list<int>		list;
		std::vector<int>	vec;

		// Plot with random numbers
		for (unsigned short i = 0; i < 4; i++)
		{
			int	n = get_random();
			mstack.push(n);
			list.push_back(n);
			vec.push_back(n);
		}

		// Print Containers
		std::cout << GREEN << "MutantStack :" << RESET << std::endl;
		print_container(mstack);
		std::cout << GREEN << "List  :" << RESET << std::endl;
		print_container(list);
		std::cout << GREEN << "Vector  :" << RESET << std::endl;
		print_container(vec);

		// Add 42 at the end
		mstack.push(42);
		list.push_back(42);
		vec.push_back(42);

		// Print Containers
		std::cout << GREEN << "MutantStack :" << RESET << std::endl;
		print_container(mstack);
		std::cout << GREEN << "List  :" << RESET << std::endl;
		print_container(list);
		std::cout << GREEN << "Vector  :" << RESET << std::endl;
		print_container(vec);

		// Remove last element two times
		mstack.pop();
		mstack.pop();
		list.pop_back();
		list.pop_back();
		vec.pop_back();
		vec.pop_back();

		// Print Containers
		std::cout << GREEN << "MutantStack :" << RESET << std::endl;
		print_container(mstack);
		std::cout << GREEN << "List  :" << RESET << std::endl;
		print_container(list);
		std::cout << GREEN << "Vector  :" << RESET << std::endl;
		print_container(vec);

		// Copy constructor	/ Copy assignment overload
		MutantStack<int>	constructor_copy(mstack);
		MutantStack<int>	assignment_copy = mstack;

		// Print Containers
		std::cout << GREEN << "MutantStack :" << RESET << std::endl;
		print_container(mstack);
		std::cout << GREEN << "Copy constructor MutantStack :" << RESET << std::endl;
		print_container(constructor_copy);
		std::cout << GREEN << "Assignment overload MutantStack :" << RESET << std::endl;
		print_container(assignment_copy);

		// Test with a constant MutantStack
		std::cout << GREEN << "Constant MutantStack :" << RESET << std::endl;
		const MutantStack<int>	constant(mstack);
		print_container(constant);
	}

	
	std::cout << std::endl << YELLOW << "Tests from the subject :" << RESET << std::endl;
	std::cout << GREEN << "Using MutantStack" << RESET << std::endl;

	// Provided main
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << GREEN << "Now using std::list" << RESET << std::endl;

	// Provided main BUT WITH AN std::list
	{
		std::list<int>	mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << *--mstack.end() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}

	std::cout << GREEN << "Now using std::vector" << RESET << std::endl;

	// Provided main BUT WITH AN std::vector
	{
		std::vector<int>	mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << *--mstack.end() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::vector<int> s(mstack);
	}

	std::cout << GREEN << "📝 Compare them all !" << RESET << std::endl;

	// MutantStack<int>	mm;
	// mm.emplace();

	return (0);
}
