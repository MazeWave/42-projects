/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:46:50 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/22 19:10:00 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_philos *philos, t_rules *rules)
{
	unsigned int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return ;
}
