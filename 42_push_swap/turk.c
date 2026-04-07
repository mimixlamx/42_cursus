/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   turk.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/24 14:50:00 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/07 12:40:00 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rush_b(t_data *data)
{
	while (data->size_a > 3)
		exec_order(data, "pb");
	sort_3(data);
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

void	turk(t_data *data)
{
	int	index;

	rush_b(data);
	while (data->size_b > 0)
	{
		cost_b(data);
		cost_a(data);
		total_cost(data);
		index = best_choice(data);
		if (data->cost_a[index] >= 0 && data->cost_b[index] >= 0)
			move_pos(data, index);
		else if (data->cost_a[index] <= 0 && data->cost_b[index] <= 0)
			move_neg(data, index);
		else
			move_both(data, index);
		exec_order(data, "pa");
		free_all(data);
	}
	index = index_min(data);
	if (index > data->size_a / 2)
		while (index < data->size_a)
		{
			exec_order(data, "rra");
			index++;
		}
	else
		while (index > 0)
		{
			exec_order(data, "ra");
			index--;
		}
}
