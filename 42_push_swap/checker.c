/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   checker.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/08 12:42:40 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/08 12:49:45 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_int(t_data *data)
{
	int	i;
	int	y;
	int	len;

	len = 0;
	i = 0;
	while (i < data->size_a)
	{
		y = 0;
		if (!data->array[i] || !data->array[i][0])
			return (0);
		len = ft_strlen(data->array[i]);
		if (data->array[i][y] == '-' || data->array[i][y] == '+')
			y++;
		if (!data->array[i][y])
			return (0);
		while (y < len)
		{
			if (data->array[i][y] < '0' || data->array[i][y] > '9')
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	check_duplicates(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (i < data->size_a)
	{
		while (y < data ->size_a)
		{
			if (data->stack_a[i] == data->stack_a[y])
				return (0);
			y++;
		}
		i++;
		y = i + 1;
	}
	return (1);
}

int	is_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_a - 1)
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
