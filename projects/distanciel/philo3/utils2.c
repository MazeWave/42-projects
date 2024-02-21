/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:55:16 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/04 16:49:15 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_struct(t_rules *data)
{
	printf("argv[1] = %s\n", data->argv[1]); 
	data->nb_phi = ft_atoi(ft_truncate(data->argv[1]));
	data->die_t = ft_atoi(ft_truncate(data->argv[2]));
	data->eat_t = ft_atoi(ft_truncate(data->argv[3]));
	data->slp_t = ft_atoi(ft_truncate(data->argv[4]));
	if (data->argc == 6)
		data->m_eat = ft_atoi(ft_truncate(data->argv[5]));
	else
		data->m_eat = -1;
	return ;
}

void	print_struct(t_rules *data)
{
	printf("---======|||||||||||||||||||======---\n");
	printf("nb_phi	: %d\n", data->nb_phi);
	printf("die_t	: %d\n", data->die_t);
	printf("eat_t	: %d\n", data->eat_t);
	printf("slp_t	: %d\n", data->slp_t);
	printf("m_eat	: %d\n", data->m_eat);
	printf("---======|||||||||||||||||||======---\n");
	return ;
}

long int	get_t(void)
{
	struct timeval		ctime;
	long int			time;

	gettimeofday(&ctime, NULL);
	time = (ctime.tv_sec * 1000) + (ctime.tv_usec / 1000);
	return(time);
}

long int	elaps_t(t_rules *rules)
{
	return (get_t() - rules->start_t);
}

void	print_msg(t_rules *data, int id, char *msg)
{
	pthread_mutex_lock(&data->write);
	if (data->can_write == 1 && data->phi[id].stop == 0)
		printf("%lu %d %s\n", elaps_t(data), id + 1, msg);
	pthread_mutex_unlock(&data->write);
}