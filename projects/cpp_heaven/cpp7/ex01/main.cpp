/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <ldalmass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:13 by ldalmass          #+#    #+#             */
/*   Updated: 2024/12/10 16:14:05 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int		main(void)
{
	int			a[3] = {-42, 0, 42};
	std::string	b[2] = {"Hello", "World!"};

	iter<int>(a, 3, print_data);
	iter<std::string>(b, 2, print_data);
	return (0);
}
