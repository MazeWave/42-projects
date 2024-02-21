/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:59:04 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/04 21:48:35 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*int	take_forks(t_phi *phi, t_forks *forks)
{
	// cas ou c'est le dernier philo : il doit prendre la fork suivante (la première fork), pour ne pas segfault
	if (phi->id == phi->rules->nb_phi - 1)
	{
		//lock sa fork (gauche)
		pthread_mutex_lock(&forks->fork[phi->id]);
		phi->forks->lock[phi->id] = 1;
		print_msg(phi->rules, phi->id, "\x1B[31m has taken a fork 1\x1B[0m");
		//lock la fork de droite
		pthread_mutex_lock(&forks->fork[0]);
		phi->forks->lock[0] = 1;
		print_msg(phi->rules, phi->id, "\x1B[31m has taken a fork 2\x1B[0m");
		return (1);
	}
	// cas normal, il prends la fork suivante
	else if (phi->forks->lock[phi->id] == 0 && phi->forks->lock[phi->id + 1] == 0)
	{
		//lock sa fork (gauche)
		phi->forks->lock[phi->id] = 1;
		pthread_mutex_lock(&forks->fork[phi->id]);
		print_msg(phi->rules, phi->id, "has taken a fork 1");
		//lock la fork de droite
		phi->forks->lock[phi->id + 1] = 1;
		pthread_mutex_lock(&forks->fork[phi->id + 1]);
		print_msg(phi->rules, phi->id, "has taken a fork 2");
		return (1);
	}
	return (0);
}*/

int	take_forks(t_phi *phi)
{
	// cas ou c'est le dernier philo : il doit prendre la fork suivante (la première fork), pour ne pas segfault
	if (phi->id == phi->rules->nb_phi - 1)
	{
		if (phi->rules->f_lock[phi->id] == 0 && phi->rules->f_lock[0] == 0)
		{
			//lock sa fork (gauche)
			pthread_mutex_lock(&phi->rules->forks[phi->id]);
			phi->rules->f_lock[phi->id] = 1;
			pthread_mutex_unlock(&phi->rules->forks[phi->id]);
			print_msg(phi->rules, phi->id, "\x1B[31m has taken a fork\x1B[0m");
			//lock la fork de droite
			pthread_mutex_lock(&phi->rules->forks[0]);
			phi->rules->f_lock[0] = 1;
			pthread_mutex_unlock(&phi->rules->forks[0]);
			print_msg(phi->rules, phi->id, "\x1B[31m has taken a fork\x1B[0m");
			return (1);
		}
		else
			return (0);
	}
	// cas normal, il prends la fork suivante
	else if (phi->rules->f_lock[phi->id] == 0 && phi->rules->f_lock[phi->id + 1] == 0)
	{
		//lock sa fork (gauche)
		pthread_mutex_lock(&phi->rules->forks[phi->id]);
		phi->rules->f_lock[phi->id] = 1;
		pthread_mutex_unlock(&phi->rules->forks[phi->id]);
		print_msg(phi->rules, phi->id, "has taken a fork");
		//lock la fork de droite
		pthread_mutex_lock(&phi->rules->forks[phi->id + 1]);
		phi->rules->f_lock[phi->id + 1] = 1;
		pthread_mutex_unlock(&phi->rules->forks[phi->id + 1]);
		print_msg(phi->rules, phi->id, "has taken a fork");
		return (1);
	}
	return (0);
}

void	drop_forks(t_phi *phi)
{
	//si dernier philo, éviter de segfault
	if (phi->id == phi->rules->nb_phi - 1)
	{
		pthread_mutex_lock(&phi->rules->forks[phi->id]);
		phi->rules->f_lock[phi->id] = 0;
		pthread_mutex_unlock(&phi->rules->forks[phi->id]);
		pthread_mutex_lock(&phi->rules->forks[0]);
		phi->rules->f_lock[0] = 0;
		pthread_mutex_unlock(&phi->rules->forks[0]);
		return ;
		//printf("\x1B[31m DROPPED LAST and 0 FORKSSSSSS\x1B[0m \n\n");
	}
	else
	{
		pthread_mutex_lock(&phi->rules->forks[phi->id + 1]);
		phi->rules->f_lock[phi->id + 1] = 0;
		pthread_mutex_unlock(&phi->rules->forks[phi->id + 1]);
		pthread_mutex_lock(&phi->rules->forks[phi->id]);
		phi->rules->f_lock[phi->id] = 0;
		pthread_mutex_unlock(&phi->rules->forks[phi->id]);
		return ;
	}
	//printf("%lu %d dropped forks\n", elaps_t(phi->rules), phi->id + 1);
	return ;
}

void	a_think(t_phi *phi)
{
	print_msg(phi->rules, phi->id, "is thinking");
	while (phi->stop == 0)
	{
		if (take_forks(phi) == 1)
			break;
	}
	return ;
}

void	a_eat(t_phi *phi)
{
	// print et usleep
	print_msg(phi->rules, phi->id, "is eating");
	usleep(phi->rules->eat_t * 1000);
	// log le time du last eat
	pthread_mutex_lock(&phi->last_eat_l);
	phi->last_eat = get_t();
	pthread_mutex_unlock(&phi->last_eat_l);
	// log le eat_counter
	pthread_mutex_lock(&phi->eat_c_l);
	phi->eat_c++;
	pthread_mutex_unlock(&phi->eat_c_l);
	// drop les forks et return
	drop_forks(phi);
	return ;
}

void	a_sleep(t_phi *phi)
{
	if (phi->stop == 1)
		return ;
	print_msg(phi->rules, phi->id, "is sleeping");
	usleep(phi->rules->slp_t * 1000);
	return ;
}
