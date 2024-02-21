/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:52:52 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/09 23:09:55 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_min_wait(t_rules *rules)
{
	int	min;

	min = 2147483647;
	if (rules->die_t < min)
		min = rules->die_t;
	if (rules->eat_t < min)
		min = rules->eat_t;
	if (rules->slp_t < min)
		min = rules->slp_t;
	return (min);
}

int	eat_enough(t_rules *rules)
{
	int	i;
	int	min_eat;
	int	must_eat;

	i = -1;
	min_eat = 2147483647;
	must_eat = rules->m_eat;
	if (must_eat == -1)
		return (0);
	while (++i < rules->nb_phi)
	{
		pthread_mutex_lock(&rules->phi[i].eat_c_l);
		if (min_eat > rules->phi[i].eat_c)
			min_eat = rules->phi[i].eat_c;
		pthread_mutex_unlock(&rules->phi[i].eat_c_l);
	}
	if (min_eat >= rules->m_eat)
		return (1);
	return (0);
}

int	take_forks(t_phi *phi)
{
	if (phi->id == phi->rules->nb_phi - 1)
	{
		if (check_fork(phi, phi->id) == 0 && check_fork(phi, 0) == 0)
		{
			if (phi->rules->nb_phi <= 1)
				return (0);
			set_fork(phi->rules, phi->id, 1);
			print_msg(phi->rules, phi->id, "\x1B[31mhas taken a fork\x1B[0m");
			set_fork(phi->rules, 0, 1);
			print_msg(phi->rules, phi->id, "\x1B[31mhas taken a fork\x1B[0m");
			return (1);
		}
		else
			return (0);
	}
	else if (check_fork(phi, phi->id) == 0 && check_fork(phi, phi->id + 1) == 0)
	{
		set_fork(phi->rules, phi->id, 1);
		print_msg(phi->rules, phi->id, "has taken a fork");
		set_fork(phi->rules, phi->id + 1, 1);
		print_msg(phi->rules, phi->id, "has taken a fork");
		return (1);
	}
	return (0);
}

void	drop_forks(t_phi *phi)
{
	if (phi->id == phi->rules->nb_phi - 1)
	{
		set_fork(phi->rules, phi->id, 0);
		set_fork(phi->rules, 0, 0);
		return ;
	}
	else
	{
		set_fork(phi->rules, phi->id, 0);
		set_fork(phi->rules, phi->id + 1, 0);
		return ;
	}
	return ;
}
