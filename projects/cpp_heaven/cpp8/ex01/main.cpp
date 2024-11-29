/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/11/29 01:28:48 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static int	get_random(void)
{
	return (rand() - std::numeric_limits<int>::max());
}

int		main(void)
{
	
	// Out of range test
	std::cout << YELLOW << "Out of range tests : " << RESET << std::endl;
	Span	oor(4);
	Span	oor2(3);

	// Plots oor
	oor.addNumber(1);
	oor.addNumber(2);
	oor.addNumber(3);
	oor.addNumber(4);

	// Tests
	try { oor.addNumber(1); }// should throw outOfRangeException
	catch ( std::exception &error ) { std::cout << error.what() << std::endl; }
	oor.printNumbers();

	// Prints


	// Copy assignment test
	std::cout << YELLOW << "Copy assignment tests : " << RESET << std::endl;
	oor2.addNumber(0);
	oor2.addNumber(0);
	oor2.addNumber(0);
	oor2.printNumbers();
	try { oor2 = oor; }
	catch ( std::exception &error ) { std::cout << error.what() << std::endl; }
	oor2.printNumbers();

	// Shortest / Longest Span test
	std::cout << YELLOW << "Shortest / Longest Span tests : " << RESET << std::endl;
	Span	a_span(5);
	a_span.addNumber(-42);
	a_span.addNumber(10);
	a_span.addNumber(15);
	a_span.addNumber(16);
	a_span.addNumber(20);
	a_span.printNumbers();
	a_span.shortestSpan();
	a_span.longestSpan();

	Span	lil_span(1);
	lil_span.addNumber(1);
	try { lil_span.shortestSpan(); }
	catch ( std::exception &error ) { std::cout << error.what() << std::endl; }
	try { lil_span.longestSpan(); }
	catch ( std::exception &error ) { std::cout << error.what() << std::endl; }

	Span	same_span(4);
	same_span.addNumber(1);
	same_span.addNumber(2);
	same_span.addNumber(1);
	same_span.addNumber(2);
	same_span.shortestSpan();
	same_span.longestSpan();

	// Random and big ass span test
	srand(time(NULL));	//generate a random seed based on time

	std::cout << YELLOW << "Random and big ass span tests : " << RESET << std::endl;
	Span				large(1000000);
	std::vector<int>	range(large.getLen());
	std::generate(range.begin(), range.end(), &get_random);
	large.addRange(range.begin(), range.end());
	// large.printNumbers();
	std::cout << CYAN << "Processing Shortest Span..." << RESET << std::endl;
	large.shortestSpan();
	std::cout << CYAN << "Processing Longest Span..." << RESET << std::endl;
	large.longestSpan();

	// Provided main:

	// std::cout << YELLOW << "Main from the subject : " << RESET << std::endl;
	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	
	return (0);
}
