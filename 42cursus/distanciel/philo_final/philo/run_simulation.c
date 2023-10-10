/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:39:48 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/09 23:09:31 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	stop_simulation(t_rules *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_phi)
	{
		pthread_join(data->phi[i].thread, NULL);
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->phi[i].last_eat_l);
		pthread_mutex_destroy(&data->phi[i].survive_l);
		pthread_mutex_destroy(&data->phi[i].eat_c_l);
		pthread_mutex_destroy(&data->phi[i].stop_l);
	}
	return ;
}

void	run_simulation(t_rules *data)
{
	pthread_t	watchdog;
	int			i;

	i = -1;
	pthread_mutex_init(&data->write, NULL);
	data->start_t = get_t();
	pthread_create(&watchdog, NULL, &watcher, data);
	while (++i < data->nb_phi)
	{
		data->phi[i].id = i;
		data->phi[i].rules = data;
		data->f_lock[i] = 0;
		data->phi[i].stop = 0;
		data->phi[i].survive = 0;
		pthread_mutex_init(&data->phi[i].stop_l, NULL);
		pthread_mutex_init(&data->phi[i].eat_c_l, NULL);
		pthread_mutex_init(&data->phi[i].survive_l, NULL);
		pthread_mutex_init(&data->phi[i].last_eat_l, NULL);
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_create(&data->phi[i].thread, NULL, &routine, &data->phi[i]);
	}
	stop_simulation(data);
	pthread_mutex_destroy(&data->write);
	pthread_join(watchdog, NULL);
	return ;
}
