/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:51:34 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/17 16:54:24 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_r);
	print_timestamp(philo, FORK);
	if (philo->philo_count == 1)
	{
		ft_sleep(philo->time_to_die * 2, philo);
		pthread_mutex_unlock(&philo->fork_r);
		return ;
	}
	pthread_mutex_lock(philo->fork_l);
	print_timestamp(philo, FORK);
	print_timestamp(philo, EAT);
	philo->eating = 1;
	pthread_mutex_lock(philo->e_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->e_lock);
	ft_sleep(philo->time_to_eat, philo);
	philo->eating = 0;
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(&philo->fork_r);
}

void	philo_think(t_philo *philo)
{
	print_timestamp(philo, THINK);
}

void	philo_sleep(t_philo *philo)
{
	print_timestamp(philo, SLEEP);
	ft_sleep(philo->time_to_sleep, philo);
}
