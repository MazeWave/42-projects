/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:58:24 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/24 17:46:27 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philos	*local;
	int			die_t;
	int			eat_t;
	int			sleep_t;

	local = data;
	die_t = local->rules->die_t;
	eat_t = local->rules->eat_t;
	sleep_t = local->rules->sleep_t;
	// philo thinking (trying to get 2 forks)
	printf("TIME %d is thinking\n", local->id + 1);
	while (die_t > 0)
	{		
		// si fork[i] et fork[i+1] unlocked : mettre lock[i] et lock[i+1] à 1
		// si fork[i] && fork[i+1] locked par nous :
		// continuer la routine en dehors du death timer

		// cas ou c'est le dernier philo et il doit prendre la première fork, pour ne pas segfault
		if (local->id == local->rules->nb_philo - 1)
		{
			if (local->locked == 0 && local->rules->philos[0].locked == 0)
			{
				local->locked = 1;
				pthread_mutex_lock(&local->fork);
				printf("TIME %d has taken a fork\n", local->id + 1);
				local->rules->philos[local->id + 1].locked = 1;
				pthread_mutex_lock(&local->rules->philos[0].fork);
				printf("TIME %d has taken a fork\n", local->id + 1);
				break;
			}
		}
		// cas normal, il prends la fork suivante
		else if (local->locked == 0 && local->rules->philos[local->id + 1].locked == 0)
		{
			local->locked = 1;
			pthread_mutex_lock(&local->fork);
			printf("TIME %d has taken a fork\n", local->id + 1);
			local->rules->philos[local->id + 1].locked = 1;
			pthread_mutex_lock(&local->rules->philos[local->id + 1].fork);
			printf("TIME %d has taken a fork\n", local->id + 1);
			break;
		}
		// death timer
		usleep(1000);
		die_t--;
	}
	// check if a philo is dead
	if (die_t <= 0)
	{
		printf("TIME %d is dead.\n", local->id + 1);
		exit(EXIT_FAILURE);
		//close_philo(local, 1);
	}
	// if not, make the philo eat
	else
	{
		printf("TIME %d is eating\n", local->id + 1);
		usleep(eat_t * 1000);
		pthread_mutex_unlock(&local->fork);
		local->locked = 0;
		pthread_mutex_unlock(&local->rules->philos[local->id + 1].fork);
		local->rules->philos[local->id + 1].locked = 0;
	}
	// make the philo sleep after eating
	printf("TIME %d is sleeping\n", local->id + 1);
	usleep(sleep_t * 1000);
	return (NULL);
}
