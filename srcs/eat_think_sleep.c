/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:51:34 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/15 12:36:07 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void philo_eat(t_philo *philo)
{
	
}

void philo_think(t_philo *philo)
{
	print_timestamp(philo->id, THINK);
}

void philo_sleep(t_philo *philo)
{
	print_timestamp(philo->id, SLEEP);
	ft_sleep(philo->time_to_sleep);
}
