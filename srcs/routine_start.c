/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:18:37 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/16 10:17:03 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	join_threads(t_data *data, t_philo *philos, pthread_t *waiter)
{
	int i;
	int ret;

	
	i = 0;
	if (pthread_join(&waiter, NULL) != 0)
		return (-1);
	while (i < data->philo_count)
	{
		ret = pthread_join(philos[i].thread, NULL);
		if (ret != 0)
			return (-1);
		i++;
	}
	return (0);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(500);
	while (!check_any_deaths(philo))
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
	int			ret;
	pthread_t	waiter;

	i = 0;
	if (pthread_create(&waiter, NULL, &monitor, philos) != 0)
		return (-1); //errfree
	while(i < data->philo_count)
	{
		ret = pthread_create(&philos[i].thread, NULL, &routine, NULL);
		if (ret != 0)
			return (-1); //errmsg
		i++;
	}
	if (join_threads(data, philos, waiter) != 0)
	{
		destroy_all(data, philos);
		return (1);
	}
	return (0);
}


