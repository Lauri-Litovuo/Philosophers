/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:44:09 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/15 17:22:21 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static int monitor_deaths(t_philo *philos);
static int check_meals_eaten(t_philo *philos);

void *monitor(void	*ptr)
{
	t_philo *philos;

	philos = (t_philo *)ptr;
	while (1)
	{
		if (monitor_deaths(philos) == 1 || check_meals_eaten(philos) == 1)
			break ;
	}
	return (ptr);
}

static int monitor_deaths(t_philo *philos)
{
	
}

static int check_meals_eaten(t_philo *philos)
{
	
}