/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:24:14 by ldalmass          #+#    #+#             */
/*   Updated: 2023/10/09 19:11:15 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_malloc(t_rules *rules)
{
	free(rules->forks);
	free(rules->f_lock);
	free(rules->phi);
	return ;
}

int	main(int argc, char **argv)
{
	t_rules	reglement;
	t_rules	*rules;

	rules = &reglement;
	rules->argc = argc;
	rules->argv = argv;
	rules->can_write = 1;
	if (parser(rules) != 0)
		return (1);
	rules->phi = malloc(sizeof(t_phi) * ft_atoi(argv[1]));
	rules->f_lock = malloc(sizeof(int) * ft_atoi(argv[1]));
	rules->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!rules->phi || !rules->forks || !rules->f_lock)
		return (1);
	fill_struct(rules);
	run_simulation(rules);
	free_malloc(rules);
	return (0);
}

/*
	//memset(rules->phi, 0, sizeof(t_phi) * rules->nb_phi);
	//memset(rules->f_lock, 0, sizeof(int) * rules->nb_phi);
	//memset(rules->forks, 0, sizeof(pthread_mutex_t) * rules->nb_phi);
*/