/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:52:31 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/22 18:51:58 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules			le_reglement;
	t_rules			*rules;
	t_philos		*philos;

	rules = &le_reglement;
	rules->argc = argc;
	rules->argv = argv;
	if (parser(rules) != 0)
	{
		usage();
		return (1);
	}
	print_struct(rules);
	philos = malloc(sizeof(t_philos) * rules->nb_philo);
	if (!philos)
		return (1);
	create_threads(philos, rules);
	join_threads(philos, rules);
	printf("Fin\n");
	//close_philo(philo);
	return (0);
}
