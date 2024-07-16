/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:26:11 by llitovuo          #+#    #+#             */
/*   Updated: 2024/07/16 14:32:57 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	input_error_msg(int errcode)
{
	if (errcode == NOTDIGIT)
	{
		write(2, "Only positive numbers are allowed as arguments.\n", 48);
	}
	if (errcode == ZERO)
	{
		write(2, "Number's value must be bigger than zero.\n", 41);
	}
	if (errcode == COUNT)
	{
		write(2, "Invalid number of arguments (4-5 required)\n", 44);
	}
}
