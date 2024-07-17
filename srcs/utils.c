/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:43:58 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/17 16:53:48 by llitovuo         ###   ########.fr       */
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

void	print_timestamp(t_philo *philo, int stampcode)
{
	size_t	cur_time;

	pthread_mutex_lock(philo->w_lock);
	cur_time = get_current_time() - philo->starting_time;
	if (check_any_deaths(philo) == 0)
	{
		if (stampcode == FORK)
			printf("%ld %d has taken a fork\n", cur_time, philo->id);
		else if (stampcode == EAT)
			printf("%ld %d is eating\n", cur_time, philo->id);
		else if (stampcode == SLEEP)
			printf("%ld %d is sleeping\n", cur_time, philo->id);
		else if (stampcode == THINK)
			printf("%ld %d is thinking\n", cur_time, philo->id);
		else if (stampcode == DEAD)
			printf("%ld %d died\n", cur_time, philo->id);
	}
	pthread_mutex_unlock(philo->w_lock);
}

static int	skip_signs(const char *str, int i)
{
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	return (i);
}

static int	ft_isneg(const char *str, int i)
{
	if (str[i] == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	long int	result;
	int			negative;
	int			i;

	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	negative = ft_isneg(str, i);
	i = skip_signs(str, i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result >= (LONG_MAX / 10) && \
				(result > LONG_MAX / 10 || str[i] - '0' > LONG_MAX % 10))
		{
			if (negative == 1)
				return (-1);
			else
				return (0);
		}
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (negative * (int)result);
}
