/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:04:26 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/16 15:20:03 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		*nums;
	t_philo	*philos;

	if (ac < 5 || ac > 6)
	{
		input_error_msg(COUNT);
		return (1);
	}
	nums = validate_and_alloc_input(ac, av);
	if (!nums)
		return (1);
	init_data(&data, nums, ac);
	philos = malloc (data.philo_count * sizeof(t_philo));
	if (!philos)
		return (1);
	init_philos(&data, &philos);
	if (start_routines(&data, philos) != 0)
		return (free_and_destroy_all(&data, philos), 1);
	free_and_destroy_all(&data, philos);
	return (0);
}
