/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_alloc_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 09:56:16 by llitovuo          #+#    #+#             */
/*   Updated: 2024/04/04 14:07:47 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static int	check_for_digits(int ac, char **av);
static int	args_to_ints(char *arg);
static int	ft_strlen(char *str);
static int	ft_isdigit(int c);

int	*validate_and_alloc_input(int ac, char **av)
{
	int	*data;
	int	i;

	data = NULL;
	if (check_for_digits(ac, av) != 0)
	{
		input_error_msg(NOTDIGIT);
		return (NULL);
	}
	data = (int *) malloc (ac * sizeof(int));
	if (!data)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		data[i] = args_to_ints(av[i + 1]);
		if (data[i] == 0)
		{
			input_error_msg(ZERO);
			return (free(data), NULL);
		}
		i++;
	}
	data[i] = 0;
	return (data);
}


static int	check_for_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (j < (int)ft_strlen(av[i + 1]))
		{
			if (ft_isdigit(av[i + 1][j]) == 0)
				return (NOTDIGIT);
			j++;
		}
		i++;
	}
	return (0);
}

static int	args_to_ints(char *arg)
{
	long long int	num;

	num = 0;
	if (!arg || arg[0] == '\0')
		return (-1);
	while (*arg != '\0')
	{
		if (*arg >= '0' && *arg <= '9')
		{
			num = num * 10 + *arg - '0';
		}
		else
			return (-1);
		arg++;
	}
	return ((int)num);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}


