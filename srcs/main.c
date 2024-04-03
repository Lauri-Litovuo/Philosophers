/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:04:26 by llitovuo          #+#    #+#             */
/*   Updated: 2024/04/03 15:50:02 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

//check max_values
static long long int	philo_count(char *number_of_philos)
{
	long long int	num;

	num = 0;
	if (!number_of_philos || number_of_philos[0] == '\0')
		return (-1);
	while (*number_of_philos != '\0')
	{
		if (*number_of_philos >= '0' && *number_of_philos <= '9')
		{
			num = num * 10 + *number_of_philos - '0';
		}
		else
			return (-1);
		number_of_philos++;
	}
	return (num);
}

int	main(int ac, char **av)
{
	pthread_t	*thread;
	long long int			num_of_philos;

	if (ac < 4)
		return (0);
	num_of_philos = philo_count(av[1]);
	if (num_of_philos < 2)
		return (1);
	thread = (pthread_t *) malloc ()
	return (0);
}
