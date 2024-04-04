/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:04:26 by llitovuo          #+#    #+#             */
/*   Updated: 2024/04/04 14:13:29 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

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
	int			*data;

	if (ac < 5 || ac > 6)
	{
		input_error_msg(COUNT);
		return (COUNT);
	}
	data = validate_and_alloc_input(ac, av);
	if (!data)
		return (1);
	thread = create_threads(num_of_philos);
	if (thread == NULL)
		return (2);
	join_threads(num_of_philos, thread);
	free (thread);
	if (data)
		free(data);
	return (0);
}
