/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   reverse_rotate.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/23 14:42:41 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/23 14:46:15 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	int	i;
	int	temp;

	if (data->size_a <= 0)
		return ;
	i = data->size_a - 1;
	temp = data->stack_a[i];
	while (i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}
	data->stack_a[0] = temp;
}

void	rrb(t_data *data)
{
	int	i;
	int	temp;

	if (data->size_b <= 0)
		return ;
	i = data->size_b - 1;
	temp = data->stack_b[i];
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}
	data->stack_b[0] = temp;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
