/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   turk.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/24 14:50:00 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/24 17:18:50 by mbruyere       ########   odam.nl        */
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

int		targeted_pos(t_data *data)
{
	int	i;

	i = 0;
	while (data->stack_b[0] > data->stack_a[i])
		i++;
	return (i);
}

int	cost_return(t_data *data)
{
	int	*cost_b;
	int	*cost_a;
	int	i;

	i = 0;
	cost_b = ft_calloc(data->size_b, sizeof(int));
	cost_a = ft_calloc(data->size_b, sizeof(int));

	while (i < data->size_b)
	{
		if (i <= (data->size_b / 2))
			cost_b[i] = i;
		else
			cost_b[i] = i - data->size_b;
		i++;
	}

}

void	turk(t_data *data)
{
	rush_b(data);
	sort_3(data);
}
