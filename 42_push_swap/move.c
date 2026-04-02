/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   move.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/02 16:11:22 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/02 17:42:41 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	move_pos(t_data *data, int index)
{
	int	i;

	i = ft_min (data->cost_a[index], data->cost_b[index]);
	while (i > 0)
	{
		rr(data);
		ft_printf("rr\n");
		data->cost_a[index]--;
		data->cost_b[index]--;
		i--;
	}
	while (data->cost_a[index] > 0)
	{
		ra(data);
		ft_printf("ra\n");
		data->cost_a[index]--;
	}
	while (data->cost_b[index] > 0)
	{
		rb(data);
		ft_printf("rb\n");
		data->cost_b[index]--;
	}
}

void	move_neg(t_data *data, int index)
{
	int	i;

	i = ft_max(data->cost_a[index], data->cost_b[index]);
	while (i < 0)
	{
		rrr(data);
		ft_printf("rrr\n");
		data->cost_a[index]++;
		data->cost_b[index]++;
		i++;
	}
	while (data->cost_a[index] < 0)
	{
		rra(data);
		ft_printf("rra\n");
		data->cost_a[index]++;
	}
	while (data->cost_b[index] < 0)
	{
		rrb(data);
		ft_printf("rrb\n");
		data->cost_b[index]++;
	}
}

void	move_both(t_data *data, int index)
{
	while (data->cost_a[index] < 0)
	{
		rra(data);
		ft_printf("rra\n");
		data->cost_a[index]++;
	}
	while (data->cost_b[index] < 0)
	{
		rrb(data);
		ft_printf("rrb\n");
		data->cost_b[index]++;
	}
	while (data->cost_a[index] > 0)
	{
		ra(data);
		ft_printf("ra\n");
		data->cost_a[index]--;
	}
	while (data->cost_b[index] > 0)
	{
		rb(data);
		ft_printf("rb\n");
		data->cost_b[index]--;
	}
}
