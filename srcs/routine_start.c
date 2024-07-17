/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:18:37 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/17 16:52:46 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
	{
		philo_think(philo);
		ft_sleep(philo->time_to_eat / 2, philo);
	}
	while (check_any_deaths(philo) == 0)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (ptr);
}

int	start_routines(t_data *data, t_philo *philos)
{
	int			i;
	pthread_t	waiter;

	i = 0;
	if (pthread_create(&waiter, NULL, &monitor, philos) != 0)
		return (create_error(data, philos, -1));
	while (i < data->philo_count)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
			return (create_error(data, philos, i));
		i++;
	}
	if (pthread_join(waiter, NULL) != 0)
		return (join_error(data, philos, data->philo_count - 1));
	i--;
	while (i >= 0)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (join_error(data, philos, i));
		i--;
	}
	return (0);
}
