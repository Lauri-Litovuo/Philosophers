/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:28:21 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/16 14:47:09 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	free_and_destroy_all(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&philo[i].fork_r);
		free(&philo[i]);
		i++;
	}
	free (philo);
	pthread_mutex_destroy(&data->w_lock);
	pthread_mutex_destroy(&data->d_lock);
	pthread_mutex_destroy(&data->e_lock);
}

void	free_and_destroy_len(t_data *data, t_philo *philo, int len)
{
	while (len > 0)
	{
		pthread_mutex_destroy(&philo[len].fork_r);
		free(&philo[len]);
		len--;
	}
	free (philo);
	pthread_mutex_destroy(&data->w_lock);
	pthread_mutex_destroy(&data->d_lock);
	pthread_mutex_destroy(&data->e_lock);
}

