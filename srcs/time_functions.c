/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:37:15 by llitovuo          #+#    #+#             */
/*   Updated: 2024/04/04 15:15:13 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	ft_sleep(int time_in_ms)
{
	unsigned long	elapsed_time;
	t_times			start;
	t_times			end;

	gettimeofday(&start, 0);
	elapsed_time = 0;
	time_in_ms *= 1000;
	while (elapsed_time < time_in_ms)
	{
		gettimeofday(&end, 0);
		elapsed_time = \
		((end.sec * 1000000) + end.usec) - ((start.sec * 1000000) + start.usec);
	}
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
