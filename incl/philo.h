/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:59:19 by llitovuo          #+#    #+#             */
/*   Updated: 2024/04/04 09:59:19 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h> //if write

typedef enum e_state
{
	EAT = 1,
	SLEEP = 2,
	THINK = 3
}	t_state;

typedef struct s_data
{
	unsigned int	philo_count;
	unsigned int	sleep_time;
	unsigned int	eating_time;
	unsigned int	die_time;
	unsigned int	eat_count;
	int				flag;
}	t_data;

#endif