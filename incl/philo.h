/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:59:19 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/17 16:53:56 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_state
{
	EAT = 1,
	SLEEP = 2,
	THINK = 3,
	FORK = 4,
	DEAD = 5
}	t_state;

typedef enum e_input_error
{
	ZERO = -1,
	NOTDIGIT = -2,
	COUNT = -3
}	t_input_error;

typedef struct s_times
{
	time_t		sec;
	suseconds_t	usec;
}	t_times;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			starting_time;
	int				philo_count;
	int				max_meals;
	int				*philo_dead;
	pthread_mutex_t	fork_r;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*w_lock;
	pthread_mutex_t	*d_lock;
	pthread_mutex_t	*e_lock;
}	t_philo;

typedef struct s_data
{
	int				dead_flag;
	pthread_mutex_t	w_lock;
	pthread_mutex_t	d_lock;
	pthread_mutex_t	e_lock;
	int				philo_count;
	int				max_meals;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
}		t_data;

int		*validate_and_alloc_input(int ac, char **av);

void	input_error_msg(int errcode);
int		mutex_error(char *str, int errcode, t_data *data);
int		thread_mutex_error(t_data *data, t_philo **philos, int i);
int		join_error(t_data *data, t_philo *philos, int i);
int		create_error(t_data *data, t_philo *philos, int i);

int		init_data(t_data *data, int ac, char **av);
int		init_philos(t_data *data, t_philo **philos);

void	*monitor(void	*ptr);

int		check_any_deaths(t_philo *philo);
void	print_timestamp(t_philo *philo, int stampcode);
int		ft_atoi(const char *str);

void	ft_sleep(size_t time_in_ms, t_philo *philo);
size_t	get_current_time(void);

int		start_routines(t_data *data, t_philo *philos);

void	free_and_destroy_all(t_data *data, t_philo *philo);
void	free_and_destroy_len(t_data *data, t_philo *philo, int len);

void	philo_eat(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);

#endif
