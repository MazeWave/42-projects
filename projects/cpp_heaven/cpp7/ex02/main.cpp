/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/12/19 15:57:26 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int		main(void)
{
	// Int array
	Array<int>	ints(42);
	for (unsigned short i = 0; i < ints.size(); i++)	// Plot array
		ints[i] = i + 1;
	for (unsigned short i = 0; i < ints.size(); i++)	// Print array
		i == ints.size() - 1 ? std::cout << ints[i] << std::endl : std::cout << ints[i] << ", ";

	// std::string array (complex type)
	Array<std::string>	strings(2);
	strings[0] = static_cast<std::string>("Hello ");
	strings[1] = static_cast<std::string>("World !");
	std::cout << strings[0] << strings[1] << std::endl;
	strings[1] = static_cast<std::string>("Friend !");
	std::cout << strings[0] << strings[1] << std::endl;

	// 4 sized unploted array
	Array<int>	unploted(4);
	for (unsigned short i = 0; i < unploted.size(); i++)
		std::cout << unploted[i] << std::endl;

	// Int NULL array
	Array<int>	nulled(0);

	try
	{
		// std::cout << nulled[0] << std::endl;
		// ints[42] = -1;
		// std::cout << ints[42] << std::endl;
		// std::cout << ints[-1] << std::endl;	// Will yse the unsigned int max value (underflow)
	}
	catch (std::exception &error) { std::cout << error.what() << std::endl; }

	// Very big array
	// Array<int>	big(10000);
	// for (unsigned int i = 0; i < big.size(); i++)		// Plot array
	// 	big[i] = i + 1;
	// for (unsigned short i = 0; i < big.size(); i++)	// Print array
	// 	i == big.size() - 1 ? std::cout << big[i] << std::endl : std::cout << big[i] << ", ";


	const Array<int>	constant(5);
	// constant[3] = 42;
	return (0);
}


/*PROVIDED MAIN*/
// #include <iostream>
// #include <cstdlib>

// #define MAX_VAL 750

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
