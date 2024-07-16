/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:51:34 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/16 15:50:37 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_r);
	print_timestamp(philo->id, FORK);
	if (philo->philo_count == 1)
	{
		ft_sleep(philo->time_to_die, philo);
		return ;
	}
	pthread_mutex_lock(philo->fork_l);
	print_timestamp(philo->id, FORK);
	pthread_mutex_lock(philo->e_lock);
	print_timestamp(philo->id, EAT);
	philo->eating = 1;
	ft_sleep(philo->time_to_eat, philo);
	pthread_mutex_unlock(philo->e_lock);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

void	philo_think(t_philo *philo)
{
	print_timestamp(philo->id, THINK);
}

void	philo_sleep(t_philo *philo)
{
	print_timestamp(philo->id, SLEEP);
	ft_sleep(philo->time_to_sleep, philo);
}
