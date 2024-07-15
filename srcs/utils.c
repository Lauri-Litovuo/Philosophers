/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:43:58 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/15 12:31:28 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	check_any_deaths(t_philo *philo)
{
	pthread_mutex_lock(philo->d_lock);
	if (*philo->philo_dead == 1)
	{
		pthread_mutex_unlock(philo->d_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->d_lock);
	return (0);
}

void	print_timestamp(int philo_num, int stampcode)
{
	t_times	cur_time;

	gettimeofday(&cur_time, 0);
	if (stampcode == FORK)
		printf("%d %d has taken a fork\n", (cur_time.usec / 1000), philo_num);
	if (stampcode == EAT)
		printf("%d %d is eating\n", (cur_time.usec / 1000), philo_num);
	if (stampcode == SLEEP)
		printf("%d %d is sleeping\n", (cur_time.usec / 1000), philo_num);
	if (stampcode == THINK)
		printf("%d %d is thinking\n", (cur_time.usec / 1000), philo_num);
	if (stampcode == DEAD)
		printf("%d %d is thinking\n", (cur_time.usec / 1000), philo_num);
}