/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   easy_sort.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/16 15:12:48 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/02 18:16:58 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_data *data)
{
	if (data->stack_a[0] > data->stack_a[1])
		exec_order(data, "sa");
}

void	sort_3(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->stack_a[0];
	b = data->stack_a[1];
	c = data->stack_a[2];
	if (a > b && b < c && a < c)
		exec_order(data, "sa");
	else if (a > b && b > c)
	{
		exec_order(data, "sa");
		exec_order(data, "rra");
	}
	else if (a > b && b < c && a > c)
		exec_order(data, "ra");
	else if (a < b && b > c && a < c)
	{
		exec_order(data, "sa");
		exec_order(data, "ra");
	}
	else if (a < b && b > c && a > c)
		exec_order(data, "rra");
}

int	index_min(t_data *data)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = data->stack_a[i];
	index = 0;
	while (i < data->size_a)
	{
		if (data->stack_a[i] < min)
		{
			min = data->stack_a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	sort_5(t_data *data)
{
	while (data->size_a > 3)
	{
		if (index_min(data) == 0)
			exec_order(data, "pb");
		else if (index_min(data) >= (data->size_a / 2))
			exec_order(data, "rra");
		else
			exec_order(data, "ra");
	}
	sort_3(data);
	exec_order(data, "pa");
	exec_order(data, "pa");
}
