/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   turk.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/24 14:50:00 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/02 16:43:38 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rush_b(t_data *data)
{
	while (data->size_a > 3)
	{
		pb(data);
		ft_printf("pb\n");
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
		if (!found)
			min = index_min(data);
		if (min <= data->size_a / 2)
			data->cost_a[i] = min;
		else
			data->cost_a[i] = min - data->size_a;
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

int	best_choice(t_data *data)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = data->total_cost[i];
	index = 0;
	while (i < data->size_b)
	{
		if (data->total_cost[i] < min)
		{
			min = data->total_cost[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	free_all(t_data *data)
{
	free(data->cost_a);
	free(data->cost_b);
	free(data->total_cost);
	data->cost_a = NULL;
	data->cost_b = NULL;
	data->total_cost = NULL;
}

void	turk(t_data *data)
{
	int	index;
	int	i;

	i = 0;
	rush_b(data);
	sort_3(data);
	while (data->size_b > 0)
	{
		cost_b(data);
		cost_a(data);
		total_cost(data);
		index = best_choice(data);
		ft_printf("best choice = %d cost = %d\n", index, data->total_cost[index]);
		if (data->cost_a[index] >= 0 && data->cost_b[index] >= 0)
			move_pos(data, index);
		else if (data->cost_a[index] <= 0 && data->cost_b[index] <= 0)
			move_neg(data, index);
		else
			move_both(data, index);
		pa(data);
		ft_printf("pa\n");
		free_all(data);
	}
}
