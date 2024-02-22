/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/14 19:40:56 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (lil_parsing(argv[1], argv[2], argv[3]) == false)
			return (parsing_failed());
		else if (file_parsing(argv[1]) == false)
			return (file_failed());
		else
			return (replace(argv[1], argv[2], argv[3]));
	}
	else
		return (print_usage());
	return (0);
}

int		replace(std::string input_file, std::string search, std::string replace)
{
	// Create the output file / clean the already existing file
	std::ofstream output((input_file + ".replace").c_str(), std::ios::trunc);
	if (output.is_open() == false)
	{
		std::cout << RED << "Error : Failed to open the output file" << RESET << std::endl;
		output.close();
		return (1);
	}

	// Setup variables
	size_t			i = -1;
	size_t			pos = 0;
	std::ifstream	input;
	input.open(input_file.c_str(), std::ios::in);

	// Dump all the input file's content
	std::string temp((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
	// std::cout << YELLOW << "-------- Content --------" << RESET << std::endl;
	// std::cout << temp;
	// std::cout << YELLOW << "-------------------------" << RESET << std::endl;

	// Overwrite the occurrence with the replacement word
	while ((pos = temp.find(search, pos)) != std::string::npos)
	{
		// Write until the occurance start
		while (++i < pos)
			output << temp[i];
		// Write the new word and offset the cursor
		output << replace;
		pos += search.length() - 1;
		i += search.length() - 1;
		
	}

	// Write until the end of the file
	pos = temp.length();
	while (++i < pos)
		output << temp[i];

	// Closes the file to avoid leaks or permanent hook on the file
	input.close();
	output.close();
	return (0);
}

bool	file_parsing(char *input)
{
	std::ifstream	file;

	file.open(input, std::ios::in);
	if (file.is_open() == true)
	{
		file.close();
		return (true);
	}
	else
	{
		file.close();
		return (false);
	}
	return (false);
}

bool	lil_parsing(std::string file, std::string search, std::string replace)
{
	if (file.empty() == true || search.empty() == true || replace.empty() == true)
		return (false);
	else if (file.length() == 0 || search.length() == 0 || replace.length() == 0)
		return (false);
	else
		return (true);
	return (false);
}

int		parsing_failed(void)
{
	std::cout << RED << "Error : input parsing failed" << RESET << std::endl;
	return (1);
}

int		file_failed(void)
{
	std::cout << RED << "Error : failed to load your file" << RESET << std::endl;
	return (1);
}

int		print_usage(void)
{
	std::cout << RESET << "How to use ./Replace :" << RESET << std::endl;
	std::cout << RESET << "./Replace" << RESET;
	std::cout << GREEN << " [YOUR-FILE]" << RESET;
	std::cout << RED << " [THE-WORD]" << RESET;
	std::cout << BLUE << " [BY-THIS-ONE]" << RESET;
	std::cout << RESET << "" << RESET << std::endl;

	return(1);
}
