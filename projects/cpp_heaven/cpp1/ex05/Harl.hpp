/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:06 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/16 15:03:00 by ldalmass         ###   ########.fr       */
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
class   Harl
{
    private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);

    public:
    Harl(void);
    ~Harl(void);
    void    complain(std::string level);
};

/****************** FUNCTIONS *******************/
void	print_usage(void);

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
