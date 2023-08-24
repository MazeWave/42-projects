/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:40:26 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/24 17:38:43 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_philos *philos, t_rules *rules)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < rules->treshold)
	{
		while (j < rules->nb_philo)
		{
			philos[j].id = j;
			philos[j].rules = rules;
			pthread_mutex_init(&philos[j].fork, NULL);
			pthread_create(&philos[j].thread, NULL, &routine, &philos[j]);
			pthread_mutex_destroy(&philos[j].fork);
			j++;
		}
		i++;
	}
	return ;
}
