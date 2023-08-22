/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:40:30 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/22 18:28:51 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_struct(t_rules *philo)
{
	printf("nb_philo	: %d\n", philo->nb_philo);
	printf("die_t		: %d\n", philo->die_t);
	printf("eat_t		: %d\n", philo->eat_t);
	printf("sleep_t		: %d\n", philo->sleep_t);
	if (philo->argc == 6)
		printf("treshold	: %d\n", philo->treshold);
	return ;
}
