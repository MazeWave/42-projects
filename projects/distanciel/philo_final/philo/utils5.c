/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:00:01 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/10 15:19:02 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_last_eat(t_phi *phi, int id)
{
	long int	value;

	pthread_mutex_lock(&phi[id].last_eat_l);
	value = phi[id].last_eat;
	pthread_mutex_unlock(&phi[id].last_eat_l);
	return (value);
}
