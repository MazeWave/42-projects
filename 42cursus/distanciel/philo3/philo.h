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

# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_rules
{
	int					argc;
	char				**argv;
	int					nb_phi;
	int					die_t;
	int					eat_t;
	int					slp_t;
	int					m_eat;
	long int			start_t;
	int					can_write;
	pthread_mutex_t		write;
	int					*f_lock;
	pthread_mutex_t		*forks;
	struct s_phi		*phi;
}						t_rules;

typedef struct s_phi
{
	int					id;
	int					stop;
	pthread_mutex_t		stopped;
	int					eat_c;
	long int			last_eat;
	pthread_t			thread;
	t_rules				*rules;
}						t_phi;

int			ft_atoi(const char *str);
int			ft_strlen(const char *str);
int			ft_strlcpy(char *dst, const char *src, int dstsize);
int			ft_strncmp(const char *s1, const char *s2, int len);
char		*ft_truncate(char *str);
void		fill_struct(t_rules *data);
void		print_struct(t_rules *data);
int			parser(t_rules *data);
long int	get_t(void);
long int	elaps_t(t_rules *rules);
void		print_msg(t_rules *data, int id, char *msg);
int			take_forks(t_phi *phi);
void		drop_forks(t_phi *phi);
void		a_think(t_phi *phi);
void		a_eat(t_phi *phi);
void		a_sleep(t_phi *phi);
int			eat_enough(t_rules *rules);
void		run_simulation(t_rules *data);
void		*watcher(void *data);
void		*routine(void *data);

/*void				close_philo(void *data, int error_code);
unsigned long long	get_current_time(void);
unsigned long long	get_elapsed_time(t_rules *rules);
int					parser(t_rules *philo);
int					check_limits(t_rules *rules);
int					parse_argv(t_rules *philo);
int					ft_atoi(const char *str);
void				init_struct(t_rules *philo);
int					check_input_value(t_rules *philo);
void				create_threads(t_philos *philos, t_rules *rules);
void				*routine(void *data);
int					take_forks(t_philos *local);
void				eat(t_philos *local);
int					is_dead(t_philos *data);
int					eat_treshold_checker(t_rules *data);
void				join_threads(t_philos *philos, t_rules *rules);*/

#endif