/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:43:58 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/16 15:47:09 by llitovuo         ###   ########.fr       */
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

void	print_timestamp(int philo_id, int stampcode)
{
	size_t cur_time;

	cur_time = get_current_time();
	if (stampcode == FORK)
		printf("%ld %d has taken a fork\n", cur_time, philo_id);
	if (stampcode == EAT)
		printf("%ld %d is eating\n", cur_time, philo_id);
	if (stampcode == SLEEP)
		printf("%ld %d is sleeping\n", cur_time, philo_id);
	if (stampcode == THINK)
		printf("%ld %d is thinking\n", cur_time, philo_id);
	if (stampcode == DEAD)
		printf("%ld %d died\n", cur_time, philo_id);
}

/*void	print_timestamp(int philo_id, int stampcode)
{
	t_times	cur_time;

	gettimeofday(&cur_time, 0);
	if (stampcode == FORK)
		printf("%ld %d has taken a fork\n", (cur_time.usec / 1000), philo_id);
	if (stampcode == EAT)
		printf("%ld %d is eating\n", (cur_time.usec / 1000), philo_id);
	if (stampcode == SLEEP)
		printf("%ld %d is sleeping\n", (cur_time.usec / 1000), philo_id);
	if (stampcode == THINK)
		printf("%ld %d is thinking\n", (cur_time.usec / 1000), philo_id);
	if (stampcode == DEAD)
		printf("%ld %d died\n", (cur_time.usec / 1000), philo_id);
}*/
