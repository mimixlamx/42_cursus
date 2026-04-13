/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   flood_fill.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/02/12 14:09:46 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/13 12:34:27 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	flood_fill(int x, int y, t_check *check)
{
	if (x < 0 || y < 0 || x >= check->h || y >= check->w)
		return (0);
	if (check->visited_map[x][y] == '1' || check->visited_map[x][y] == 'V')
		return (0);
	if (check->visited_map[x][y] == 'C')
		check->found_c++;
	if (check->visited_map[x][y] == 'E')
	{
		check->found_e++;
		check->visited_map[x][y] = 'V';
		return (0);
	}
	check->visited_map[x][y] = 'V';
	flood_fill(x + 1, y, check);
	flood_fill(x - 1, y, check);
	flood_fill(x, y + 1, check);
	flood_fill(x, y - 1, check);
	return (1);
}

int	flood_fil_launch(t_check *check)
{
	int		i;

	i = 0;
	check->found_c = 0;
	check->found_e = 0;
	check->visited_map = ft_calloc(check->h + 1, sizeof(char *));
	if (!check->visited_map)
		return (0);
	while (i < check->h)
	{
		check->visited_map[i] = ft_strdup(check->map[i]);
		if (!check->visited_map[i])
			return (0);
		i++;
	}
	flood_fill(check->x, check->y, check);
	i = 0;
	if (check->found_c != check->c || check->found_e != 1)
		return (ft_printf("Error\nin collectibles or exit e = %d c = %d\n",
				check->found_e, check->found_c), 0);
	return (1);
}
