/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:04:26 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/15 17:24:50 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"



int	main(int ac, char **av)
{
	t_data	data;
	int		*nums;
	t_philo *philos;

	if (ac < 5 || ac > 6)
	{
		input_error_msg(COUNT);
		return (1);
	}
	nums = validate_and_alloc_input(ac, av);
	if (!nums)
		return (1);
	init_struct(&data, nums);
	philos = malloc (data.philo_count *sizeof (t_philo));
	if (!philos)
		return (1);
	init_philos(&data, philos);
	if (start_routines(&data, philos) != 0)
		return (free_and_destroy_all(data, philos), 1);
	destroy_all_mutexes(data, philos);
	free_philos(philos);
	return (0);
}
