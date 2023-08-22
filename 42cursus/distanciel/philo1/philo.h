/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:52:26 by ldalmass          #+#    #+#             */
/*   Updated: 2023/08/22 14:52:26 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_rules
{
	int					argc;
	char				**argv;
	unsigned int		nb_philo;
	unsigned int		die_t;
	unsigned int		eat_t;
	unsigned int		sleep_t;
	unsigned int		treshold;
}				t_rules;

typedef struct s_philos
{
	unsigned int		id;
	pthread_t			thread;
	t_rules				*rules;
}				t_philos;

void				print_struct(t_rules *philo);
void				usage(void);
//void				close_philo(t_philo *philo);
int					parser(t_rules *philo);
int					parse_argv(t_rules *philo);
unsigned int		ft_atoi(const char *str);
void				init_struct(t_rules *philo);
int					check_input_value(t_rules *philo);
void				create_threads(t_philos *philos, t_rules *rules);
void				*routine(void *data);
void				join_threads(t_philos *philos, t_rules *rules);

#endif