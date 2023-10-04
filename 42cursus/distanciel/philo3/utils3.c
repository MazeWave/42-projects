/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:09:10 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/04 17:21:37 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_enough(t_rules *rules)
{
	int	i;
	int	min_eat;
	int	must_eat;

	i = -1;
	min_eat = 0;
	must_eat = rules->m_eat;
	// case for no max eat entered
	if (must_eat == -1)
		return (0);
	// recode of min fonction
	while (++i < rules->nb_phi)
	{
		pthread_mutex_lock(&rules->phi[i].eat_c_l);
		if (min_eat > rules->phi[i].eat_c)
			min_eat = rules->phi[i].eat_c;
		pthread_mutex_unlock(&rules->phi[i].eat_c_l);
	}
	// check if we reached the minimum eat threshold for each philosopher
	if (min_eat >= rules->eat_t)
		return (1);
	return (0);
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