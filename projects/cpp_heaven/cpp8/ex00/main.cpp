/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/30 00:45:27 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

static int	get_random(void)
{
	return (rand() - std::numeric_limits<int>::max());
}

int		main(void)
{
	srand(time(NULL));	//generate a random seed based on time

	int	len = 1000000;
	std::cout << std::endl;
	std::cout << "📈 container size = " << len << std::endl;
	std::cout << std::endl;

	std::list<int>		list;
	std::vector<int>	vec;

	// Plot containers wit random numbers
	for (int i = 0; i < len; i++)
	{
		int n = get_random();
		list.push_back(n);
		vec.push_back(n);
	}

	int	to_find = vec[(rand() % len)];	// randomly choose an existing number to find
	int	to_search = get_random();

	// to_find tests
	std::cout << CYAN << "⏭️ Existing number to_find = " << to_find << RESET << std::endl;
	std::cout << YELLOW << "list container test" << RESET << std::endl;
	try { easyfind(list, to_find); }
	catch (std::exception &error) { std::cout << error.what() << std::endl; return (1);}
	std::cout << GREEN << "✅ Number found in the container." << RESET << std::endl;
	std::cout << YELLOW << "vector container test" << RESET << std::endl;
	try { easyfind(vec, to_find); }
	catch (std::exception &error) { std::cout << error.what() << std::endl; return (1); }
	std::cout << GREEN << "✅ Number found in the container." << RESET << std::endl;

	std::cout << std::endl;

	// to_search tests
	std::cout << CYAN << "🔀 Random number to_search = " << to_search << RESET << std::endl;
	std::cout << YELLOW << "list container test" << RESET << std::endl;
	try { easyfind(list, to_search); }
	catch (std::exception &error) { std::cout << error.what() << std::endl; }
	std::cout << YELLOW << "vector container test" << RESET << std::endl;
	try { easyfind(vec, to_search); }
	catch (std::exception &error) { std::cout << error.what() << std::endl; }
	return (0);
}
