/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/02/16 16:09:41 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
		print_usage();
	else
	{
		Harl		log;
		log.complain(argv[1]);
	}
	return (0);
}

void	print_usage(void)
{
	std::cout << GREEN << "Usage : " << RESET;
	std::cout << "./Harl [DEBUG/INFO/WARNING/ERROR]" << std::endl;
	return;
}
