/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   move_utils.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/02 16:14:01 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/02 16:34:41 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_max(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_a);
	return (cost_b);
}

int	ft_min(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_b);
	return (cost_a);
}

int	ft_abs(int cost)
{
	if (cost < 0)
		return (cost * -1);
	return (cost);
}
