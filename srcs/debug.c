/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:46:35 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/17 09:56:19 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void print_data(t_data *data)
{
	printf("dead_flag: %d\n", data->dead_flag);
	printf("philo_count: %d\n", data->philo_count);
	printf("time to die:%zu\n", data->time_to_die);
	printf("time to eat: %zu\n", data->time_to_eat);
	printf("time to sleep: %zu\n", data->time_to_sleep);
	printf("max meals: %d\n", data->max_meals);
}

void print_nums(int *nums, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		printf("num%d %d\n", i, nums[i]);
		i++;
	}
}
