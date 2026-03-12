/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   fload_fill.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/02/12 14:09:46 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/12 12:03:28 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	flood_fill(int x, int y, t_check *check)
{
	ft_printf ("inside floodfill\n");
	if (x < 0 || y < 0 || x > check->h || y > check->w)
		return (ft_printf("out of mapp\n"), 0);
	if (check->visited_map[x][y] == '1' || check->visited_map[x][y] == 'V')
		return (ft_printf("reach wall or visited\n"), 0);
	if (check->visited_map[x][y] == 'C')
		check->found_c++;
	if (check->visited_map[x][y] == 'E')
		check->found_e++;
	check->visited_map[x][y] = 'V';
	ft_printf ("count this bitch %s \n", check->visited_map[x]);
	flood_fill(x + 1, y, check);
	flood_fill(x - 1, y, check);
	flood_fill(x, y + 1, check);
	flood_fill(x, y - 1, check);
	return (ft_printf("floodfill end\n"), 1);
}

int	flood_fil_launch(t_check *check)
{
	int		i;

	i = 0;
	check->found_c = 0;
	check->found_e = 0;
	check->visited_map = ft_calloc(check->h + 1, sizeof(char *));
	while (i < check->h)
	{
		check->visited_map[i] = ft_strdup(check->map[i]);
		ft_printf("v_map[%d] = %s w = %d\n", i, check->visited_map[i], check->w);
		i++;
	}
	ft_printf("launch %d %d %d %d\n", check->w, check->h, check->x, check->y);
	flood_fill(check->x, check->y, check);
	i = 0;
	while (i < check->h)
	{
		ft_printf("v_map[%d] = %s w = %d\n", i, check->visited_map[i], check->w);
		i++;
	}
	if (check->found_c != check->c || check->found_e != 1)
		return (ft_printf("error in colictibles or exit e = %d c = %d\n",
				check->found_e, check->found_c), 0);
	return (ft_printf("no error in floodfill\n"), 1);
}
