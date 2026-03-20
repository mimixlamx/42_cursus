/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   check_map.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/02/10 14:27:41 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/20 17:02:12 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	check_inside_line(int i, int y, t_check *check)
{
	if (check->map[i][0] == '1' && check->map[i][check->w - 1] == '1')
		y++;
	else
		return (ft_printf("Error\nborder line map[%d]\n", i), 0);
	while (y > 0 && y < check->w - 1)
	{
		if (ft_strchr("01PEC", check->map[i][y]))
		{
			if (check->map[i][y] == 'P')
			{
				check->x = i;
				check->y = y;
				check->p++;
			}
			else if (check->map[i][y] == 'E')
				check->e++;
			else if (check->map[i][y] == 'C')
				check->c++;
			y++;
		}
		else
			return (ft_printf("Error\nchar %c in position[%d][%d]\n",
					check->map[i][y], i, y), 0);
	}
	return (1);
}

static int	check_first_last_line(int i, int y, t_check *check)
{
	while (y < check->w)
	{
		if (check->map[i][y] == '1')
			y++;
		else
			return (ft_printf("Error\nin line %d not only 1\n", i), 0);
	}
	return (1);
}

static int	check_in_map(t_check *check)
{
	int	i;
	int	y;

	check->p = 0;
	check->c = 0;
	check->e = 0;
	y = 0;
	i = 0;
	while (i < check->h)
	{
		if (i == 0 || i == check->h - 1)
			if (check_first_last_line(i, y, check) == 0)
				return (0);
		if (check_inside_line(i, y, check) == 0)
			return (0);
		i++;
	}
	if (check->p > 1 || check->p == 0)
		return (ft_printf("Error\n1 player needed now %d\n", check->p), 0);
	if (check->e > 1 || check->e == 0)
		return (ft_printf("Error\n1 exit needed now %d\n", check->e), 0);
	if (check->c == 0)
		return (ft_printf("Error\n1 collectible needed now %d\n", check->c), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_check	check;

	if (first_check(argc, argv, &check) == 0 || c_map(argv, &check) == 0)
		return (1);
	if (check_size_map(&check) == 0 || check_in_map(&check) == 0)
		return (free_map(&check), 1);
	if (flood_fil_launch(&check) == 0)
		return (free_map(&check), free_visited_map(&check), 1);
	free_visited_map(&check);
	launch_game(&check);
	return (0);
}
