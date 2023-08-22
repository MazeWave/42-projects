/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:10:59 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/22 18:51:28 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_rules *rules)
{
	rules->nb_philo = ft_atoi(rules->argv[1]);
	rules->die_t = ft_atoi(rules->argv[2]);
	rules->eat_t = ft_atoi(rules->argv[3]);
	rules->sleep_t = ft_atoi(rules->argv[4]);
	if (rules->argc == 6)
		rules->treshold = ft_atoi(rules->argv[5]);
	return ;
}
