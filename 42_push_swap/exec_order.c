/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   exec_order.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/02 16:45:07 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/02 18:38:37 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	exec_order_reverse_rotate(t_data *data, char *order)
{
	if (ft_strncmp(order, "rra", 4) == 0)
	{
		rra(data);
		ft_printf("rra\n");
	}
	else if (ft_strncmp(order, "rrb", 4) == 0)
	{
		rrb(data);
		ft_printf("rrb\n");
	}
	else if (ft_strncmp(order, "rrr", 4) == 0)
	{
		rrr(data);
		ft_printf("rrr\n");
	}
}

static void	exec_order_rotate(t_data *data, char *order)
{
	if (ft_strncmp(order, "ra", 3) == 0)
	{
		ra(data);
		ft_printf("ra\n");
	}
	else if (ft_strncmp(order, "rb", 3) == 0)
	{
		rb(data);
		ft_printf("rb\n");
	}
	else if (ft_strncmp(order, "rr", 3) == 0)
	{
		rr(data);
		ft_printf("rr\n");
	}
	else
		exec_order_reverse_rotate(data, order);
}

static void	exec_order_push(t_data *data, char *order)
{
	if (ft_strncmp(order, "pa", 3) == 0)
	{
		pa(data);
		ft_printf("pa\n");
	}
	else if (ft_strncmp(order, "pb", 3) == 0)
	{
		pb(data);
		ft_printf("pb\n");
	}
	else
		exec_order_rotate(data, order);
}

static void	exec_order_swap(t_data *data, char *order)
{
	if (ft_strncmp(order, "sa", 3) == 0)
	{
		sa(data);
		ft_printf("sa\n");
	}
	else if (ft_strncmp(order, "sb", 3) == 0)
	{
		sb(data);
		ft_printf("sb\n");
	}
	else if (ft_strncmp(order, "ss", 3) == 0)
	{
		ss(data);
		ft_printf("ss\n");
	}
	else
		exec_order_push(data, order);
}

void	exec_order(t_data *data, char *order)
{
	exec_order_swap(data, order);
}
