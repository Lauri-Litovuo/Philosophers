/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:44:09 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/16 15:23:25 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static int	monitor_deaths(t_philo *philos);
static int	check_meals_eaten(t_philo *philos);

void	*monitor(void	*ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
	{
		if (monitor_deaths(philos) == 1 || check_meals_eaten(philos) == 1)
			break ;
	}
	return (ptr);
}

static int	check_if_dead_for_hunger(t_philo *philo)
{
	pthread_mutex_lock(philo->e_lock);
	if (get_current_time() - philo->last_meal > philo->time_to_die
		&& philo->eating != 1)
	{
		pthread_mutex_lock(philo->e_lock);
		return (1);
	}
	pthread_mutex_lock(philo->e_lock);
	return (0);
}

static int	monitor_deaths(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].philo_count)
	{
		if (check_if_dead_for_hunger(&philos[i]) > 0)
		{
			pthread_mutex_lock(philos[i].w_lock);
			print_timestamp(philos[i].id, DEAD);
			pthread_mutex_unlock(philos[i].w_lock);
			pthread_mutex_lock(philos[i].d_lock);
			*philos[0].philo_dead = 1;
			pthread_mutex_unlock(philos[i].d_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_meals_eaten(t_philo *philos)
{
	int	dined_philo_count;
	int	i;
	int	philo_count;

	dined_philo_count = 0;
	i = 0;
	if (philos[i].max_meals == -1)
		return (0);
	philo_count = philos[i].philo_count;
	while (i < philo_count)
	{
		pthread_mutex_lock(philos[i].e_lock);
		if (philos[i].meals_eaten >= philos[i].max_meals)
			dined_philo_count++;
		pthread_mutex_unlock(philos[i].e_lock);
		i++;
	}
	if (dined_philo_count >= philo_count)
	{
		pthread_mutex_lock(philos[i].d_lock);
		*philos[0].philo_dead = 1;
		pthread_mutex_unlock(philos[i].d_lock);
		return (1);
	}
	return (0);
}
