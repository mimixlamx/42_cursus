/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   turk_utils.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/07 12:10:59 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/07 12:13:54 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
