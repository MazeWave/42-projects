/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:33:56 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/10 15:18:23 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->nb_phi)
	{
		if (elaps_t(rules) - get_last_eat(rules->phi, i)
			> rules->die_t + VARIANCE)
		{
			set_can_write(rules, 0);
			pthread_mutex_lock(&rules->write);
			printf("%lu ", elaps_t(rules));
			printf("%d died\n", rules->phi[i].id / rules->nb_phi + 1);
			pthread_mutex_unlock(&rules->write);
			return (1);
		}
		if (eat_enough(rules) == 1)
			return (1);
	}
	return (0);
}

void	*watcher(void *data)
{
	t_rules	*rules;
	int		i;

	rules = data;
	while (check_death(rules) == 0)
		i++;
	set_can_write(rules, 0);
	return (NULL);
}

void	*routine(void *data)
{
	t_phi	*phi;

	phi = data;
	while (get_write(phi->rules) == 1)
	{
		a_think(phi);
		if (get_write(phi->rules) == 0)
			break ;
		a_eat(phi);
		a_sleep(phi);
		if (get_write(phi->rules) == 0)
			break ;
	}
	return (NULL);
}
