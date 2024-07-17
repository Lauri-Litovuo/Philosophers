/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:45:46 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/17 16:53:11 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static void	setup_philo(t_data *data, t_philo *philo, int i);

int	init_data(t_data *data, int ac, char **av)
{
	data->dead_flag = 0;
	data->philo_count = ft_atoi(av[1]);
	data->time_to_die = (size_t)ft_atoi(av[2]);
	data->time_to_eat = (size_t)ft_atoi(av[3]);
	data->time_to_sleep = (size_t)ft_atoi(av[4]);
	if (ac == 6)
		data->max_meals = ft_atoi(av[5]);
	else
		data->max_meals = -1;
	if (pthread_mutex_init(&data->w_lock, NULL) != 0)
		return (mutex_error("mutex_init error\n", 1, data));
	if (pthread_mutex_init(&data->d_lock, NULL) != 0)
		return (mutex_error("mutex_init error\n", 2, data));
	if (pthread_mutex_init(&data->e_lock, NULL) != 0)
		return (mutex_error("mutex_init error\n", 3, data));
	return (0);
}

int	init_philos(t_data *data, t_philo **philos)
{
	int	i;

	i = 0;
	*philos = (t_philo *) malloc (data->philo_count * sizeof(t_philo));
	if (!(*philos))
		return (-1);
	memset(*philos, 0, data->philo_count * sizeof(t_philo));
	while (i < data->philo_count)
	{
		setup_philo(data, &(*philos)[i], (i + 1));
		if (pthread_mutex_init(&(*philos)[i].fork_r, NULL) != 0)
			return (thread_mutex_error(data, philos, i - 1));
		if (i == 0)
			(*philos)[i].fork_l = &(*philos)[data->philo_count - 1].fork_r;
		else
			(*philos)[i].fork_l = &(*philos)[i - 1].fork_r;
		i++;
	}
	return (0);
}

static void	setup_philo(t_data *data, t_philo *philo, int i)
{
	philo->id = i;
	philo->eating = 0;
	philo->meals_eaten = 0;
	philo->last_meal = 0;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->starting_time = get_current_time();
	philo->last_meal = get_current_time();
	philo->philo_count = data->philo_count;
	philo->max_meals = data->max_meals;
	philo->philo_dead = &data->dead_flag;
	philo->w_lock = &data->w_lock;
	philo->d_lock = &data->d_lock;
	philo->e_lock = &data->e_lock;
}
