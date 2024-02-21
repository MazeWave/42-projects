/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:33:56 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/04 21:13:55 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*watcher(void *data)
{
	t_rules	*rules;
	int		i;

	rules = data;
	i = -1;
	usleep(1000 * rules->die_t + 10);
	while (eat_enough(rules) == 0)
	{
		usleep(1000 * rules->eat_t);
		if (elaps_t(rules) - rules->phi[i].last_eat >= rules->die_t + 1000)
		{
			printf("////////////////////////////////STOP\n");
			set_can_write(rules, 0);
			printf("%lu %d died\n", elaps_t(rules), rules->phi[i].id + 1);
			break;
		}
	}
	i = -1;
	printf("////////////////////////////////TELLING PHILOS TO STOP\n");
	while (++i < rules->nb_phi)
		set_stop(rules->phi, i, 1);
	return (NULL);
}

void	*routine(void *data)
{
	t_phi	*phi;

	phi = data;
	//print_struct(phi->rules);
	while (phi->stop == 0)
	{
		a_think(phi);
		if (phi->stop == 1)
			break;
		a_eat(phi);
		if (phi->stop == 1)
			break;
		a_sleep(phi);
		if (phi->stop == 1)
			break;
	}
	//printf("Philo %d stopped on demand\n", phi->id + 1);
	return (NULL);
}
