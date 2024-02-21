/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:24:46 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/24 12:59:31 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input_value(t_rules *rules)
{
	if (rules->nb_philo > 2000000)
		return (1);
	if (rules->die_t > 1000000)
		return (1);
	if (rules->eat_t > 1000000)
		return (1);
	if (rules->sleep_t > 1000000)
		return (1);
	if (rules->argc == 6)
		if (rules->treshold > 1000000)
			return (1);
	return (0);
}
