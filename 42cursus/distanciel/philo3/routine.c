/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:33:56 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/03 00:48:52 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*watcher(void *data)
{
	t_rules	*rules;
	int		i;

	rules = data;
	i = -1;
	//usleep(1000 * phi->rules->die_t);
	while (eat_enough(rules) == 0)
	{
		printf("\n\n\nHERE\n\n\n");
		usleep(1000 * rules->die_t);
		if (elaps_t(rules) - rules->phi[i].last_eat >= rules->die_t)
		{
			printf("////////////////////////////////STOP\n");
			rules->can_write = 0;
			rules->phi[i].stop = 1;
			print_msg(rules, rules->phi[i].id, "died");
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
	while (phi->stop == 0)
	{
		a_think(phi);
		if (phi->stop == 1)
			break;
		a_eat(phi);
		a_sleep(phi);
	}
	print_msg(phi->rules, phi->id, "STOPPED UNEXPECTEDLY\n");
	return (NULL);
}
