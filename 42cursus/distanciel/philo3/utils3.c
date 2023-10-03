/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:09:10 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/03 18:44:57 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_enough(t_rules *rules)
{
	int	i;
	int	min_eat;
	int	must_eat;

	i = -1;
	min_eat = 0;
	must_eat = rules->m_eat;
	// case for no max eat entered
	if (must_eat == -1)
		return (0);
	// recode of min fonction
	while (++i < rules->nb_phi)
	{
		print_struct(rules);
		if (min_eat > rules->phi[i].eat_c)
			min_eat = rules->phi[i].eat_c;
	}
	// check if we reached the minimum eat threshold for each philosopher
	if (min_eat >= rules->eat_t)
		return (1);
	return (0);
}
