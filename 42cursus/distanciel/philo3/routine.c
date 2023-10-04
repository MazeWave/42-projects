/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:33:56 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/04 17:31:39 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*watcher(void *data)
{
	t_rules	*rules;
	int		i;

	rules = data;
	i = -1;
	print_struct(rules);
	//usleep(1000 * phi->rules->die_t);
	while (eat_enough(rules) == 0)
	{
		usleep(1000 * rules->die_t);
		if (elaps_t(rules) - rules->phi[i].last_eat >= rules->die_t)
		{
			printf("////////////////////////////////STOP\n");
			set_can_write(rules, 0);
			//rules->phi[i].stop = 1;
			//print_msg(rules, rules->phi[i].id, "died");
			printf("%lu %d died\n", elaps_t(rules), rules->phi[i].id);
			break;
		}

	}
	i = -1;
	printf("Shouldn't print after this message\n");
	//while (++i < rules->nb_phi)
	//	rules->phi[i].stop = 1;
	return (NULL);
}

void	*routine(void *data)
{
	t_phi	*phi;

	phi = data;
	print_struct(phi->rules);
	while (phi->stop == 0)
	{
		a_think(phi);
		a_eat(phi);
		a_sleep(phi);
	}
	print_msg(phi->rules, phi->id, "STOPPED UNEXPECTEDLY\n");
	return (NULL);
}
