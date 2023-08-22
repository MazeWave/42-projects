/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:40:26 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/22 19:10:42 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_philos *philos, t_rules *rules)
{
	pthread_mutex_t		mutex;
	unsigned int		i;

	i = 0;
	while (i < rules->nb_philo)
	{
		philos[i].id = i;
		philos[i].rules = rules;
		pthread_mutex_init(&mutex, NULL);
		pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
		pthread_mutex_destroy(&mutex);
		i++;
	}
	return ;
}
