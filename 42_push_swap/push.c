/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/16 16:16:46 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/16 18:05:30 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	int	i;
	int	temp;

	i = data->size_a;
	ft_printf("i = %d\n", i);
	if (data->size_b == 0)
		return ;
	while (i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}
	data->stack_a[0] = data->stack_b[0];
	i = 0;
	while (i < data->size_b)
	{
		data->stack_b[i] = data->stack_b[i+1];
		i++;
	}
}

void	pb(t_data *data)
{
	int	i;
	int	temp;

	i = data->size_b;
	ft_printf("i = %d\n", i);
	if (data->size_a == 0)
		return ;
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}
	data->stack_b[0] = data->stack_a[0];
	i = 0;
	while (i < data->size_a)
	{
		data->stack_a[i] = data->stack_a[i+1];
		i++;
	}
}
