/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   check_map.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/02/10 14:27:41 by mbruyere       #+#    #+#                */
/*   Updated: 2026/02/10 16:45:14 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

/*
 ** file dedicated to check the map on so long project 
*/
#include "libft.h"
/*
 ** to include the libft
 ** voir pour toutmettre dansla libft, printf etc
*/
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> // to be deleted

typedef struct	s_check
{
	char	**map;
	char	**visited_map;
	int		w;
	int		h;
	int		x;
	int		y;
	int		p;
	int		e;
	int		c;
	int		found_c;
	int		found_e;
}	t_check;

int	flood_fill(int x, int y, t_check *check)
{
	printf ("inside floodfill\n");
	if (x < 0 || y < 0 || x > check->h || y > check->w)
		return (printf("out of mapp\n"), 0);
	if (check->visited_map[x][y] == '1' || check->visited_map[x][y] == 'V')
		return (printf("reach wall or visited\n"), 0);
	if (check->visited_map[x][y] == 'C')
		check->found_c++;
	if (check->visited_map[x][y] == 'E')
		check->found_e++;
	check->visited_map[x][y] = 'V';
	printf ("count this bitch %s \n", check->visited_map[x]);
	flood_fill(x + 1, y, check);
	flood_fill(x - 1, y, check);
	flood_fill(x, y + 1, check);
	flood_fill(x, y - 1, check);
	return (printf("floodfill end\n"), 1);
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
		printf("visited_map[%d] = %s w = %d\n", i, check->visited_map[i], check->w);
		i++;
	}
	printf("launch floodfill %d %d %d %d\n", check->w, check->h, check->x, check->y);
	flood_fill(check->x, check->y, check);
	i = 0;
	while (i < check->h)
	{
		printf("visited_map[%d] = %s w = %d\n", i, check->visited_map[i], check->w);
		i++;
	}
	if (check->found_c != check->c || check->found_e != 1)
		return (printf("error in colictibles or exit e = %d c = %d\n", check->found_e, check->found_c), 0);
	return (printf("no error in floodfill\n"), 1);
}

int	check_in_map(t_check *check)
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
		{
			printf ("first or last line i = %d\n", i);
			while (y < check->w)
			{
				if (check->map[i][y] == '1')
					y++;
				else
					return (printf("error in line %d not only 1\n", i), 0);
			}
			y = 0;
		}
		else
		{
			printf ("inside lines i =%d y = %d\n", i, y);
			if (check->map[i][0] == '1' && check->map[i][check->w - 1] == '1')
				y++;
			else
				return (printf("error border line map[%d]\n", i), 0);
			while (y > 0 && y <= check->w - 2)
			{
				if (check->map[i][y] == '0' || check->map[i][y] == 'P' || check->map[i][y] == 'E' || check->map[i][y] == 'C' || check->map[i][y] == '1')
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
					return (printf("error char not ok in map %c in position [%d][%d] char %c\n", check->map[i][y], i, y, check->map[i][y]), 0);
			}
			y = 0;
		}
		i++;
	}
	if (check->p > 1 || check->p == 0)
		return (printf("1 player needed, now %d\n", check->p), 0);
	if (check->e > 1 || check->e == 0)
		return (printf("1 exit needed, now %d\n", check->e), 0);
	if (check->c == 0)
		return (printf("1 collectible  needed, now %d\n", check->c), 0);
	return (printf("no error in mapp\n"), 1);
}

int	check_size_map(t_check	*check)
{
	int	i;

	i = 1;
	check->w = ft_strlen(check->map[0]);
	while (check->map[i] && check->w == ft_strlen(check->map[i]))
	{
		printf ("len_0 = %d\n", check->w);
		printf ("len_%d= %ld\n", i, ft_strlen(check->map[i]));
		i++;
	}
	if (i != check->h)
		return (printf("error in size of a line\nlen_0 = %d vs len_%d = %zu\n", check->w, i, ft_strlen(check->map[i])), 0);
	if (check->w == check->h)
		return (printf("error square map\n"), 0);
	else
		return (printf("'no error on size mapp\n"), 1);
}

int	main(int argc, char **argv)
{
	char	*temp;
	int		i;
	int		fd;
	int		len_temp;
	t_check	check;

	check.h = 0;
	i = 0;
	if (argc != 2)
		return (printf("pls enter only the mapp as an argument\n"), 0);
	if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4)), ".ber", 4) != 0)
		return (printf ("pls enter only a .ber map\n"), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (printf("pas d'ouverture fichier inexistant?\n"), 1);
	while ((temp = get_next_line(fd)) != NULL)
		check.h++;
	printf("h = %d\n", check.h);
	if (check.h == 0)
		return (printf("empty map\n"), 0);
	check.map = ft_calloc(check.h + 1, sizeof (char *));
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while ((temp = get_next_line(fd)) != NULL)
	{
		printf ("temp %d = %s\n", i, temp);
		len_temp = ft_strlen(temp);
		if (len_temp > 0 && temp[len_temp - 1] == '\n')
			temp[len_temp - 1] = '\0';
		check.map[i] = ft_strdup(temp);
		i++;
	}
	close(fd);
	i = 0;
	while (check.map[i])
	{
		printf ("map[%d] = %s\n", i, check.map[i]);
		i++;
	}
	printf ("argc = %d\nargv = %s\n", argc, argv[1]);
	if (check_size_map(&check) == 0 || check_in_map(&check) == 0)
		return (printf("error in map formatting\n"), 1);
	if (flood_fil_launch(&check) == 0)
		return (printf("fuck floodfill\n"), 0);
	else
		return (0);
}
