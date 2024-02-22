/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/14 17:47:50 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

/************* STANDARD LIBRARIES ***************/
# include <iostream>
# include <cstdlib>
# include <string>
# include <fstream>

/******************* CLASSES ********************/
// No class needed

/****************** FUNCTIONS *******************/
int		replace(std::string input_file, std::string search, std::string replace);
int 	print_usage(void);
bool	lil_parsing(std::string file, std::string search, std::string replace);
bool	file_parsing(char *input);
int		parsing_failed(void);
int		file_failed(void);

/******************* COLORS *********************/
# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"
# define CYAN		"\033[36m"
# define MAGENTA	"\033[35m"
# define YELLOW		"\033[33m"
# define BLACK		"\033[30m"
# define WHITE		"\033[37m"

#endif
