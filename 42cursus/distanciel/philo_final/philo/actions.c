/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:59:04 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/09 23:07:19 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	a_think(t_phi *phi)
{
	print_msg(phi->rules, phi->id, "is thinking");
	while (get_write(phi->rules) == 1)
	{
		if (take_forks(phi) == 1)
			break ;
	}
	return ;
}

void	a_eat(t_phi *phi)
{
	print_msg(phi->rules, phi->id, "is eating");
	usleep(phi->rules->eat_t * 1000);
	drop_forks(phi);
	return ;
}

void	a_sleep(t_phi *phi)
{
	pthread_mutex_lock(&phi->eat_c_l);
	phi->eat_c++;
	pthread_mutex_unlock(&phi->eat_c_l);
	pthread_mutex_lock(&phi->last_eat_l);
	phi->last_eat = get_t();
	pthread_mutex_unlock(&phi->last_eat_l);
	print_msg(phi->rules, phi->id, "is sleeping");
	if (get_write(phi->rules) == 0)
		return ;
	usleep(phi->rules->slp_t * 1000);
	return ;
}
