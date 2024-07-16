/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:45:46 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/16 16:04:15 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static void	setup_philo(t_data *data, t_philo *philo, int i);

void	init_data(t_data *data, int *nums, int ac)
{
	data->dead_flag = 0;
	data->philo_count = nums[0];
	data->time_to_die = nums[1];
	data->time_to_eat = nums[2];
	data->time_to_sleep = nums[3];
	if (ac == 6)
		data->max_meals = nums[4];
	else
		data->max_meals = -1;
	free(nums);
	pthread_mutex_init(&data->w_lock, NULL);
	pthread_mutex_init(&data->d_lock, NULL);
	pthread_mutex_init(&data->e_lock, NULL);
}

void	init_philos(t_data *data, t_philo **philos)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		setup_philo(data, philos[i], i);
		pthread_mutex_init(&philos[i]->fork_r, NULL);
		if (i == 0)
			philos[i]->fork_l = philos[data->philo_count - 1]->fork_l;
		else
			philos[i]->fork_l = philos[i - 1]->fork_l;
		i++;
	}
}

static void	setup_philo(t_data *data, t_philo *philo, int i)
{
	philo->id = i + 1;
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
