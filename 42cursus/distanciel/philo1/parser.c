/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:35:52 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/22 18:50:05 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parser(t_rules *rules)
{
	if (parse_argv(rules) != 0)
		return (1);
	init_struct(rules);
	if (check_input_value(rules) != 0)
		return (1);
	return (0);
}
