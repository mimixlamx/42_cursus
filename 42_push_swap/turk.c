/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   turk.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/24 14:50:00 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/08 15:00:16 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	select_order(t_data *data)
{
	int	index;

	index = index_min(data);
	if (index > data->size_a / 2)
	{
		while (index < data->size_a)
		{
			exec_order(data, "rra");
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			exec_order(data, "ra");
			index--;
		}
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
	select_order(data);
}
