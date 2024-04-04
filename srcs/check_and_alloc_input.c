/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_alloc_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 09:56:16 by llitovuo          #+#    #+#             */
/*   Updated: 2024/04/04 10:08:28 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

t_data	*validate_and_alloc_input(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 || ac != 6) //check
		return (NULL);
	if (check_for_digit(ac, av) != 0)
		return (NULL);
	data = init_data();
	if (!data)
		return (NULL);
	if (ac == 6) //check
		data->flag = 1;
	data->philo_count = philo_count(av[1]);
	data->sleep_time = get_sleep_time(av[2]);
	data->eating_time = get_eating_time(av[3]);
	if (data->flag == 1)
		data->eat_count = get_eat_count(av[4]);
	return (data);
}