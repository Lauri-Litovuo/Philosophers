/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:59:19 by llitovuo          #+#    #+#             */
/*   Updated: 2024/04/04 12:55:59 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

typedef enum e_state
{
	EAT = 1,
	SLEEP = 2,
	THINK = 3
}	t_state;

typedef enum e_input_error
{
	ZERO = -1,
	NOTDIGIT = -2,
	COUNT = -3
}	t_input_error;

int		*validate_and_alloc_input(int ac, char **av);
void	input_error_msg(int errcode);



#endif