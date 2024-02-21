/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:56:05 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:08 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_fork(t_phi *phi, int id)
{
	int	value;

	pthread_mutex_lock(&phi->rules->forks[id]);
	value = phi->rules->f_lock[id];
	pthread_mutex_unlock(&phi->rules->forks[id]);
	return (value);
}

void	set_fork(t_rules *rules, int id, int value)
{
	pthread_mutex_lock(&rules->forks[id]);
	rules->f_lock[id] = value;
	pthread_mutex_unlock(&rules->forks[id]);
	return ;
}

int	check_write(t_rules *rules)
{
	pthread_mutex_lock(&rules->write);
	if (rules->can_write == 1)
	{
		pthread_mutex_unlock(&rules->write);
		return (1);
	}
	pthread_mutex_unlock(&rules->write);
	return (0);
}

void	set_can_write(t_rules *rules, int value)
{
	pthread_mutex_lock(&rules->write);
	rules->can_write = value;
	pthread_mutex_unlock(&rules->write);
	return ;
}

int	get_write(t_rules *rules)
{
	int	value;

	pthread_mutex_lock(&rules->write);
	value = rules->can_write;
	pthread_mutex_unlock(&rules->write);
	return (value);
}
