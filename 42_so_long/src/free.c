/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   free.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/18 12:54:15 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/20 16:32:53 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_check *check)
{
	int	i;

	i = 0;
	while (check->map && check->map[i])
	{
		free(check->map[i]);
		i++;
	}
	free(check->map);
}

void	free_visited_map(t_check *check)
{
	int	i;

	i = 0;
	while (check->visited_map && check->visited_map[i])
	{
		free(check->visited_map[i]);
		i++;
	}
	free(check->visited_map);
}
