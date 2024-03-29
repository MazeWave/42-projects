/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:39:48 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/04 20:43:03 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	run_simulation(t_rules *data)
{
	pthread_t	watchdog;
	int			i;

	i = -1;
	printf("can write value at start of the simulation: %d\n", data->can_write);
	pthread_mutex_init(&data->write, NULL);
	pthread_create(&watchdog, NULL, &watcher, data);
	data->start_t = get_t();
	// lance les threads et mutexes
	while (++i < data->nb_phi)
	{
		data->phi[i].id = i;
		data->phi[i].rules = data;
		data->f_lock[i] = 0;
		pthread_mutex_init(&data->phi[i].stop_l, NULL);
		pthread_mutex_init(&data->phi[i].last_eat_l, NULL);
		pthread_mutex_init(&data->phi[i].eat_c_l, NULL);
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_create(&data->phi[i].thread, NULL, &routine, &data->phi[i]);
		usleep(data->eat_t * 1000);
	}
	// attends l'arret des threads
	//printf("\nWaiting Watchdog do end\n\n");
	//pthread_join(watchdog, NULL);
	//while (check_write(data) == 1)
	//	usleep(data->eat_t * 1000);
	// close les threads et mutexes
	i = -1;
	while (++i < data->nb_phi)
	{
		pthread_join(data->phi[i].thread, NULL);
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->phi[i].last_eat_l);
		pthread_mutex_destroy(&data->phi[i].eat_c_l);
		pthread_mutex_destroy(&data->phi[i].stop_l);
	}
	pthread_mutex_destroy(&data->write);	
	pthread_join(watchdog, NULL);
	return ;
}