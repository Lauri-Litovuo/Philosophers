/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:04:26 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/17 16:42:45 by llitovuo         ###   ########.fr       */
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
	if (init_data(&data, ac, av) != 0)
		return (free(nums), 1);
	free(nums);
	if (init_philos(&data, &philos) != 0)
		return (1);
	if (start_routines(&data, philos) != 0)
		return (1);
	free_and_destroy_all(&data, philos);
	return (0);
}
