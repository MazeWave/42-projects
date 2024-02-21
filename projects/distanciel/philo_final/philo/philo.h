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

# define VARIANCE 0

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
	pthread_mutex_t		stop_l;
	int					eat_c;
	pthread_mutex_t		eat_c_l;
	int					survive;
	pthread_mutex_t		survive_l;
	long int			last_eat;
	pthread_mutex_t		last_eat_l;
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
int			check_fork(t_phi *phi, int id);
int			check_write(t_rules *rules);
int			get_write(t_rules *rules);
int			get_min_wait(t_rules *rules);
long int	get_last_eat(t_phi *phi, int id);
void		set_can_write(t_rules *rules, int value);
void		set_fork(t_rules *rules, int id, int value);
void		run_simulation(t_rules *data);
void		*watcher(void *data);
void		*routine(void *data);

#endif