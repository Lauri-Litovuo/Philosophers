/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:37:15 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/15 17:01:33 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;
	
	if(gettimeofday(&time, 0) < 0)
		write(2, "error: gettimeofday\n", 20);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_sleep(int time_in_ms)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < time_in_ms)
	{
		if (check_for_deaths() == 1)
			break;
		usleep(500);
	}
	return (0);
}
