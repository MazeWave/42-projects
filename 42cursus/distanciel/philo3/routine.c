/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:33:56 by ldalmass          #+#    #+#             */
/*   Updated: 2023/09/28 21:57:28 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void	*dead(void *data)
{
	t_phi	*phi;

	phi = (t_phi *)data;
	//usleep(1000 * phi->rules->die_t);
	if (phi->locked == 0) //check si il mange
		phi->stop = 1;
	return (NULL);
}*/

void	*routine(void *data)
{
	t_phi	*phi;

	phi = data;
	while (phi->stop == 0)
	{
		a_think(phi);
		a_eat(phi);
		a_sleep(phi);
	}
	return (NULL);
}
