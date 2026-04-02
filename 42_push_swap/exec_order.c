/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   exec_order.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/02 16:45:07 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/02 17:37:42 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	exec_order_reverse_rotate(t_data *data, char *order)
{
	if (ft_strncmp(order, "rra", 4) == 0)
		exec_order(data, "rra");
	else if (ft_strncmp(order, "rrb", 4) == 0)
		exec_order(data, "rrb");
	else if (ft_strncmp(order, "rrr", 4) == 0)
		exec_order(data, "rrr");
}

static void	exec_order_rotate(t_data *data, char *order)
{
	if (ft_strncmp(order, "ra", 3) == 0)
		exec_order(data, "ra");
	else if (ft_strncmp(order, "rb", 3) == 0)
		exec_order(data, "rb");
	else if (ft_strncmp(order, "rr", 3) == 0)
		exec_order(data, "rr");
	else
		exec_order_reverse_rotate(data, order);
}

static void	exec_order_push(t_data *data, char *order)
{
	if (ft_strncmp(order, "pa", 3) == 0)
		exec_order(data, "pa");
	else if (ft_strncmp(order, "pb", 3) == 0)
		exec_order(data, "pb");
	else
		exec_order_reverse_rotate(data, order);
}

static void	exec_order_swap(t_data *data, char *order)
{
	if (ft_strncmp(order, "sa", 3) == 0)
		exec_order(data, "sa");
	else if (ft_strncmp(order, "sb", 3) == 0)
		exec_order(data, "sb");
	else if (ft_strncmp(order, "ss", 3) == 0)
		exec_order(data, "ss");
	else
		exec_order_push(data, order);
}

void	exec_order(t_data *data, char *order)
{
	exec_order_swap(data, order);
}
