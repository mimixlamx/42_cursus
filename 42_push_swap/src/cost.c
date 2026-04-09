/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   cost.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/08 14:57:21 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/09 13:13:59 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	set_cost_a(t_data *data, int found, int min, int i)
{
	if (!found)
		min = index_min(data);
	if (min <= data->size_a / 2)
		data->cost_a[i] = min;
	else
		data->cost_a[i] = min - data->size_a;
}

void	cost_a(t_data *data)
{
	int	i;
	int	y;
	int	min;
	int	found;

	data->cost_a = ft_calloc(data->size_b, sizeof(int));
	i = 0;
	while (i < data->size_b)
	{
		y = 0;
		min = 0;
		found = 0;
		while (y < data->size_a)
		{
			if (data->stack_a[y] > data->stack_b[i] && (!found
					|| data->stack_a[y] < data->stack_a[min]))
			{
				min = y;
				found = 1;
			}
			y++;
		}
		set_cost_a(data, found, min, i);
		i++;
	}
}

void	cost_b(t_data *data)
{
	int	i;

	i = 0;
	data->cost_b = ft_calloc(data->size_b, sizeof(int));
	while (i < data->size_b)
	{
		if (i <= (data->size_b / 2))
			data->cost_b[i] = i;
		else
			data->cost_b[i] = i - data->size_b;
		i++;
	}
}

void	total_cost(t_data *data)
{
	int	i;

	data->total_cost = ft_calloc(data->size_b, sizeof(int));
	i = 0;
	while (i < data->size_b)
	{
		if ((data->cost_a[i] > 0 && data->cost_b[i] > 0)
			|| (data->cost_a[i] < 0 && data->cost_b[i] < 0))
			data->total_cost[i] = ft_max(ft_abs(data->cost_a[i]),
					ft_abs(data->cost_b[i]));
		else
			data->total_cost[i]
				= ft_abs(data->cost_a[i]) + ft_abs(data->cost_b[i]);
		i++;
	}
}
