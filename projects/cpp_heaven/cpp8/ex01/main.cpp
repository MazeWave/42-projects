/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/12/10 17:38:26 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static int	get_random(void)
{
	return (rand() - std::numeric_limits<int>::max() / 2);
}

int		main(void)
{
	
	// Out of range test
	std::cout << std::endl << YELLOW << "🕳️ Out of range tests : " << RESET << std::endl;
	Span	oor(4);
	Span	oor2(3);
	Span	oor3(oor2);

	// Plots oor
	oor.addNumber(1);
	oor.addNumber(2);
	oor.addNumber(3);
	oor.addNumber(4);

	// Tests
	try { oor.addNumber(1); }	// should throw outOfRangeException
	catch ( std::exception &error ) { std::cout << error.what() << std::endl; }
	std::cout << "oor :" << std::endl;
	oor.printNumbers();

	// Copy assignment / constructor test
	std::cout << std::endl << YELLOW << "📚 Copy assignment / constructor tests : " << RESET << std::endl;
	std::cout << "oor2 :" << std::endl;
	oor2.addNumber(0);
	oor2.addNumber(0);
	oor2.addNumber(0);
	oor2.printNumbers();
	try { oor2 = oor; }
	catch ( std::exception &error ) { std::cout << error.what() << std::endl; }
	std::cout << "oor2 (after copy assignation) :" << std::endl;
	oor2.printNumbers();
	std::cout << "oor3 (after copy constructor):" << std::endl;
	oor3.printNumbers();

	// Shortest / Longest Span test
	std::cout << std::endl << YELLOW << "⏬ Shortest / ⏫ Longest Span tests : " << RESET << std::endl;
	Span	a_span(5);
	a_span.addNumber(-42);
	a_span.addNumber(10);
	a_span.addNumber(15);
	a_span.addNumber(16);
	a_span.addNumber(20);
	a_span.printNumbers();
	a_span.shortestSpan();
	a_span.longestSpan();

	Span	same_span(4);
	same_span.addNumber(1);
	same_span.addNumber(2);
	same_span.addNumber(1);
	same_span.addNumber(2);
	same_span.printNumbers();
	same_span.shortestSpan();
	same_span.longestSpan();

	// Throw test
	std::cout << std::endl << YELLOW << "🗑️ Throw tests : " << RESET << std::endl;
	Span	lil_span(1);
	lil_span.addNumber(1);
	try { lil_span.shortestSpan(); }
	catch ( std::exception &error ) { std::cout << error.what() << std::endl; }
	try { lil_span.longestSpan(); }
	catch ( std::exception &error ) { std::cout << error.what() << std::endl; }

	// Random and big ass span test
	srand(time(NULL));	//generate a random seed based on time

	std::cout << std::endl << YELLOW << "🔀 Random and big ass span tests : " << RESET << std::endl;
	Span				large(1000000);
	std::vector<int>	range(large.getLen());
	std::generate(range.begin(), range.end(), &get_random);
	large.addRange(range.begin(), range.end());
	std::cout << CYAN << "⏬ Processing Shortest Span..." << RESET << std::endl;
	large.shortestSpan();
	std::cout << CYAN << "⏫ Processing Longest Span..." << RESET << std::endl;
	large.longestSpan();

	// Provided main:

	std::cout << std::endl << YELLOW << "Main from the subject : " << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	return (0);
}
