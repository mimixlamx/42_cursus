/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   swap.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/16 15:47:11 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/16 17:46:33 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	tmp;

	if (data->size_a < 2)
		return ;
	tmp = data->stack_a[0];
	data->stack_a[0] = data->stack_a[1];
	data->stack_a[1] = tmp;
	return ;
}

void	sb(t_data *data)
{
	int	tmp;

	if (data->size_b < 2)
		return ;
	tmp = data->stack_b[0];
	data->stack_b[0] = data->stack_b[1];
	data->stack_b[1] = tmp;
	return ;
}

void	ss(t_data *data)
{
	sa (data);
	sb (data);
	return ;
}
