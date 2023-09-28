/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:24:14 by ldalmass          #+#    #+#             */
/*   Updated: 2023/09/28 23:10:35 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	reglement;
	t_rules	*rules;
	//t_forks	fourchette;
	//t_forks	*forks;

	rules = &reglement;
	rules->argc = argc;
	rules->argv = argv;
	rules->can_write = 1;
	//forks = &fourchette;
	if (parser(rules) != 0)
	{
		printf("Error\n");
		return (1);
	}
	rules->phi = malloc(sizeof(t_phi) * ft_atoi(argv[1]));
	rules->forks->lock = malloc(sizeof(int) * ft_atoi(argv[1]));
	rules->forks->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!rules->phi || !rules->forks->fork || !rules->forks->lock)
	{
		printf("Error Malloc\n");
		return (1);
	}
	memset(rules->phi, 0, sizeof(t_phi) * rules->nb_phi);
	//memset(forks->lock, 0, sizeof(int) * rules->nb_phi);
	fill_struct(rules);
	//print_struct(rules);
	run_simulation(rules, rules->phi, rules->forks);
	//free_malloc(rules->phi, rules->forks);
	printf("Fin\n");
	return (0);
}
