/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   move.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/02 16:11:22 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/02 18:14:44 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	move_pos(t_data *data, int index)
{
	int	i;

	i = ft_min (data->cost_a[index], data->cost_b[index]);
	while (i > 0)
	{
		exec_order(data, "rr");
		data->cost_a[index]--;
		data->cost_b[index]--;
		i--;
	}
	while (data->cost_a[index] > 0)
	{
		exec_order(data, "ra");
		data->cost_a[index]--;
	}
	while (data->cost_b[index] > 0)
	{
		exec_order(data, "rb");
		data->cost_b[index]--;
	}
}

void	move_neg(t_data *data, int index)
{
	int	i;

	i = ft_max(data->cost_a[index], data->cost_b[index]);
	while (i < 0)
	{
		exec_order(data, "rrr");
		data->cost_a[index]++;
		data->cost_b[index]++;
		i++;
	}
	while (data->cost_a[index] < 0)
	{
		exec_order(data, "rra");
		data->cost_a[index]++;
	}
	while (data->cost_b[index] < 0)
	{
		exec_order(data, "rrb");
		data->cost_b[index]++;
	}
}

void	move_both(t_data *data, int index)
{
	while (data->cost_a[index] < 0)
	{
		exec_order(data, "rra");
		data->cost_a[index]++;
	}
	while (data->cost_b[index] < 0)
	{
		exec_order(data, "rrb");
		data->cost_b[index]++;
	}
	while (data->cost_a[index] > 0)
	{
		exec_order(data, "ra");
		data->cost_a[index]--;
	}
	while (data->cost_b[index] > 0)
	{
		exec_order(data, "rb");
		data->cost_b[index]--;
	}
}
