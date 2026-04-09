/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rotate.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/23 13:04:32 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/02 16:27:20 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	int	i;
	int	temp;
	int	y;

	if (data->size_a <= 0)
		return ;
	y = 0;
	i = data->size_a - 1;
	temp = data->stack_a[0];
	while (i > 0)
	{
		data->stack_a[y] = data->stack_a[y + 1];
		i--;
		y++;
	}
	data->stack_a[data->size_a - 1] = temp;
}

void	rb(t_data *data)
{
	int	i;
	int	temp;
	int	y;

	if (data->size_b <= 0)
		return ;
	y = 0;
	i = data->size_b - 1;
	temp = data->stack_b[0];
	while (i > 0)
	{
		data->stack_b[y] = data->stack_b[y + 1];
		i--;
		y++;
	}
	data->stack_b[data->size_b - 1] = temp;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
