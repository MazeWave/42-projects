/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:58:24 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/22 19:10:55 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philos	*local;

	local = data;
	pthread_mutex_lock(&mutex);
	printf("ID = %d\n", local->id);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}
