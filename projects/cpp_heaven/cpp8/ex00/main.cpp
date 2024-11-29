/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/27 22:08:36 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int		main(void)
{
	srand(time(NULL));	//generate a random seed based on time

	int	len = rand() % 10000;
	std::cout << "len = " << len << std::endl;

	std::list<int>					list;
	std::vector<int>				vec;
	std::map<std::string, int>		map;

	// Plot containers wit random numbers
	for (int i = 0; i < len; i++)
	{
		int n = rand() - (std::numeric_limits<int>::min());	// create a number between min int and max int
		list.push_back(n);
		vec.push_back(n);
	}

	int	to_find = vec[(rand() % len)];	// choose an existing number to find
	std::cout << "Existing number to find : (int) to_find = " << to_find << std::endl;
	int	to_search = rand() - (std::numeric_limits<int>::min());
	std::cout << "Random number to search : (int) to)_search = " << to_search << " at least " << YELLOW << "1 in [unsigned int max]" << RESET << " to find it bro" << std::endl;

	// to_find tests
	std::cout << GREEN << "to_find tests" << RESET << std::endl;
	try { easyfind(list, to_find); }
	catch (std::exception &error) { std::cout << error.what() << std::endl; }
	std::cout << "✅" << std::endl;
	try { easyfind(vec, to_find); }
	catch (std::exception &error) { std::cout << error.what() << std::endl; }
	std::cout << "✅" << std::endl;
	// to_search tests
	std::cout << GREEN << "to_search tests" << RESET << std::endl;
	try { easyfind(list, to_search); }
	catch (std::exception &error) { std::cout << error.what() << std::endl; }
	try { easyfind(vec, to_search); }
	catch (std::exception &error) { std::cout << error.what() << std::endl; }
	return (0);
}
