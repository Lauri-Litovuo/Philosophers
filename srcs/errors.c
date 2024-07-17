/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:26:11 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/17 16:52:28 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	input_error_msg(int errcode)
{
	if (errcode == NOTDIGIT)
	{
		write(2, "Only positive numbers are allowed as arguments.\n", 48);
	}
	else if (errcode == ZERO)
	{
		write(2, "Number's value must be bigger than zero.\n", 41);
	}
	else if (errcode == COUNT)
	{
		write(2, "Invalid number of arguments (4-5 required)\n", 44);
	}
}

int	mutex_error(char *str, int errcode, t_data *data)
{
	int	len;

	len = 0;
	if (str)
	{
		while (str[len] != '\0')
			len++;
		write(2, str, len);
		if (errcode == 1)
			return (1);
		else if (errcode == 2)
			pthread_mutex_destroy(&data->w_lock);
		else if (errcode == 3)
		{
			pthread_mutex_destroy(&data->w_lock);
			pthread_mutex_destroy(&data->d_lock);
		}
	}
	return (1);
}

int	thread_mutex_error(t_data *data, t_philo **philos, int i)
{
	write(2, "mutex_init error\n", 17);
	while (i >= 0)
	{
		pthread_mutex_destroy(&(*philos)[i].fork_r);
		i--;
	}
	pthread_mutex_destroy(&data->w_lock);
	pthread_mutex_destroy(&data->d_lock);
	pthread_mutex_destroy(&data->e_lock);
	return (1);
}

int	create_error(t_data *data, t_philo *philos, int i)
{
	i--;
	write(2, "pthread_create failed\n", 22);
	while (i >= 0)
	{
		pthread_join(philos[i].thread, NULL);
		i--;
	}
	free_and_destroy_all(data, philos);
	return (1);
}

int	join_error(t_data *data, t_philo *philos, int i)
{
	i--;
	write(2, "pthread_join failed\n", 22);
	while (i >= 0)
	{
		pthread_join(philos[i].thread, NULL);
		i--;
	}
	free_and_destroy_all(data, philos);
	return (1);
}
