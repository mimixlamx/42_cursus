/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   turk.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/24 14:50:00 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/25 15:58:29 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rush_b(t_data *data)
{
	while	(data->size_a > 3)
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
			if (data->stack_a[y] > data->stack_b[i] && (!found || data->stack_a[y] < data->stack_a[min]))
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

int	best_choice(t_data *data)
{
	int	i;

	i = 0;
	while (i < size_b)
	{
		if ((data->stack_a[i] > 0 && data->stack_b[i] > 0) ||
				(data->stack_a[i] < 0 && data->stack_b[i] < 0))
			;
	}
}

void	turk(t_data *data)
{
	rush_b(data);
	sort_3(data);
	cost_b(data);
	cost_a(data);
	best_choice(data);

}
