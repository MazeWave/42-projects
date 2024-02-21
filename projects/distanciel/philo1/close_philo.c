/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:55:25 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/24 16:31:10 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	close_philo(t_rules *data, int error_code)
{
	if (data->philos->rules)
		free(data->philos->rules);
	if (data->philos)
		free(data->philos);
	if (error_code == 0)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
	return ;
}
