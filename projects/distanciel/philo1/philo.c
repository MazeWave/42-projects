/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:52:31 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/24 16:48:35 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules			le_reglement;
	t_rules			*rules;

	rules = &le_reglement;
	rules->argc = argc;
	rules->argv = argv;
	if (parser(rules) != 0)
	{
		usage();
		return (1);
	}
	print_struct(rules);
	rules->philos = malloc(sizeof(t_philos) * rules->nb_philo);
	if (!rules->philos)
		return (1);
	create_threads(rules->philos, rules);
	join_threads(rules->philos, rules);
	printf("Fin\n");
	//close_philo(rules, 0);
	return (0);
}
