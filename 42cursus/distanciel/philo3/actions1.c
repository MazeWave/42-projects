/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:59:04 by ldalmass          #+#    #+#             */
/*   Updated: 2023/09/28 21:48:51 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_phi *phi, t_forks *forks)
{
	// cas ou c'est le dernier philo et il doit prendre la fork suivante (la première fork), pour ne pas segfault
	if (phi->id == phi->rules->nb_phi - 1)
	{
		if (phi->forks->lock[phi->id] == 0 && phi->forks->lock[0] == 0)
		{
			//lock sa fork (gauche)
			phi->forks->lock[phi->id] = 1;
			pthread_mutex_lock(&forks->fork[phi->id]);
			print_msg(phi->rules, phi->id, "has taken a fork");
			//lock la fork de droite
			phi->forks->lock[0] = 1;
			pthread_mutex_lock(&forks->fork[0]);
			print_msg(phi->rules, phi->id, "has taken a fork");
			return (1);
		}
	}
	// cas normal, il prends la fork suivante
	else if (phi->forks->lock[phi->id] == 0 && phi->forks->lock[phi->id + 1] == 0)
	{
		//lock sa fork (gauche)
		phi->forks->lock[phi->id] = 1;
		pthread_mutex_lock(&forks->fork[phi->id]);
		print_msg(phi->rules, phi->id, "has taken a fork");
		//lock la fork de droite
		phi->forks->lock[phi->id + 1] = 1;
		pthread_mutex_lock(&forks->fork[phi->id + 1]);
		print_msg(phi->rules, phi->id, "has taken a fork");
		return (1);
	}
	return (0);
}

void	drop_forks(t_phi *phi, t_forks *forks)
{
	//si dernier philo, éviter de segfault ou de bad unlock
	if (phi->id == phi->rules->nb_phi - 1)
	{
		pthread_mutex_unlock(&forks->fork[phi->id]);
		pthread_mutex_unlock(&forks->fork[0]);
		phi->forks->lock[phi->id] = 0;
		phi->forks->lock[0] = 0;
	}
	else
	{
		pthread_mutex_unlock(&forks->fork[phi->id]);
		pthread_mutex_unlock(&forks->fork[phi->id + 1]);
		phi->forks->lock[phi->id] = 0;
		phi->forks->lock[phi->id + 1] = 0;
	}
	printf("%lu %d dropped forks\n", elaps_t(phi->rules), phi->id);
	return ;
}

void	a_think(t_phi *phi)
{
	print_msg(phi->rules, phi->id, "is thinking");
	while (phi->stop == 0)
	{
		if (take_forks(phi, phi->forks) == 1)
			break;
	}
	return ;
}

void	a_eat(t_phi *phi)
{
	usleep(phi->rules->eat_t * 1000);
	drop_forks(phi, phi->forks);
	return ;
}

void	a_sleep(t_phi *phi)
{
	print_msg(phi->rules, phi->id, "is sleeping");
	usleep(phi->rules->slp_t * 1000);
	return ;
}
