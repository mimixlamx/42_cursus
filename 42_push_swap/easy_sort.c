/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   easy_sort.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/16 15:12:48 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/25 15:36:41 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_data *data)
{
	if (data->stack_a[0] > data->stack_a[1])
	{
		sa(data);
		ft_printf("sa\n");
	}
}

/*
 *213 sa
 *231 rra
 *312 ra
 *123 nothing
 *132 sa + ra
 *321 sa + rra
*/
void	sort_3(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->stack_a[0];
	b = data->stack_a[1];
	c = data->stack_a[2];
	if (a < b && b < c)
		;
	else if (a > b && b < c && a < c)
	{
		sa(data);
		ft_printf("ss\n");
	}
	else if (a > b && b > c)
	{
		sa(data);
		rra(data);
		ft_printf("sa\nrra\n");
	}
	else if (a > b && b < c && a > c)
	{
		ra(data);
		ft_printf("ra\n");
	}
	else if (a < b && b > c && a < c)
	{
		sa(data);
		ra(data);
		ft_printf("sa\nra\n");
	}
	else if (a < b && b > c && a > c)
	{
		rra(data);
		ft_printf("rra\n");
	}
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
		{
			pb(data);
			ft_printf("pb\n");
		}
		else if (index_min(data) >= (data->size_a / 2))
		{
			rra(data);
			ft_printf("rra\n");
		}
		else
		{
			ra(data);
			ft_printf("ra\n");
		}
	}
	sort_3(data);
	pa(data);
	pa(data);
	ft_printf("pa\npa\n");
}
