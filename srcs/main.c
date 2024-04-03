/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:04:26 by llitovuo          #+#    #+#             */
/*   Updated: 2024/04/03 17:58:51 by llitovuo         ###   ########.fr       */
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

void	*routine()
{
	printf("hey\n");
	return (NULL);
}

pthread_t	*create_threads(int num_of_philos)
{
	int			i;
	int			rv;
	pthread_t	*thread;

	i = 0;
	thread = (pthread_t *) malloc (num_of_philos * sizeof(pthread_t));
	if (!thread)
		return (NULL);
	while (i < num_of_philos)
	{
		rv = pthread_create(&thread[i], NULL, &routine, NULL);
		if (rv != 0)
			return (NULL);
		i++;
	}
	return (thread);
}
void	join_threads(int num_of_philos, pthread_t *thread)
{
	int i;
	int rv;

	i = 0;
	while (i < num_of_philos)
	{
		rv = pthread_join(thread[i], NULL);
		if (rv != 0)
			return (NULL);
	}
	return (thread);
}

int	main(int ac, char **av)
{
	pthread_t	*thread;
	int			num_of_philos;

	if (ac < 4)
		return (0);
	num_of_philos = (int)philo_count(av[1]);
	if (num_of_philos < 2)
		return (1);
	printf("%d\n", num_of_philos);
	thread = create_threads(num_of_philos);
	if (thread == NULL)
		return (2);
	join_threads(num_of_philos, thread);
	free (thread);
	return (0);
}
