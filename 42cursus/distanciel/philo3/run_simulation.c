/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:39:48 by ldalmass          #+#    #+#             */
/*   Updated: 2023/09/28 22:05:42 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	run_simulation(t_rules *data, t_phi *phi, t_forks *forks)
{
	int	i;

	data->start_t = 0;
	
	i = -1;
	data->start_t = get_t();
	while (++i < data->nb_phi)
	{
		phi[i].id = i;
		phi[i].rules = data;
		forks->lock[i] = 0;
		//pthread_mutex_init(&phi[i].fork, NULL);
		pthread_create(&phi[i].thread, NULL, &routine, &phi[i]);
	}
	i = -1;
	while (++i < data->nb_phi)
	{
		
	}	
	return ;
}