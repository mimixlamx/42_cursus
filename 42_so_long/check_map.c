/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   check_map.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/02/10 14:27:41 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/12 12:01:55 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	check_inside_line(int i, int y, t_check *check)
{
	if (check->map[i][0] == '1' && check->map[i][check->w - 1] == '1')
		y++;
	else
		return (ft_printf("error border line map[%d]\n", i), 0);
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
			return (ft_printf("error char %c in position[%d][%d] char %c\n",
					check->map[i][y], i, y, check->map[i][y]), 0);
	}
	return (1);
}

static int	check_first_last_line(int i, int y, t_check *check)
{
	ft_printf ("first or last line i = %d\n", i);
	while (y < check->w)
	{
		if (check->map[i][y] == '1')
			y++;
		else
			return (ft_printf("error in line %d not only 1\n", i), 0);
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
		return (ft_printf("1 player needed, now %d\n", check->p), 0);
	if (check->e > 1 || check->e == 0)
		return (ft_printf("1 exit needed, now %d\n", check->e), 0);
	if (check->c == 0)
		return (ft_printf("1 collectible  needed, now %d\n", check->c), 0);
	return (ft_printf("no error in mapp\n"), 1);
}

static int	check_size_map(t_check	*check)
{
	int	i;

	i = 1;
	check->w = ft_strlen(check->map[0]);
	while (check->map[i] && check->w == ft_strlen(check->map[i]))
	{
		ft_printf ("len_0 = %d\n", check->w);
		ft_printf ("len_%d= %ld\n", i, ft_strlen(check->map[i]));
		i++;
	}
	if (i != check->h)
		return (ft_printf("error in size line\nlen_0 = %d vs len_%d = %zu\n",
				check->w, i, ft_strlen(check->map[i])), 0);
	if (check->w == check->h)
		return (ft_printf("error square map\n"), 0);
	else
		return (ft_printf("no error on size mapp\n"), 1);
}

static int	first_check(int argc, char **argv, t_check *check)
{
	char	*temp;
	int		fd;

	check->h = 0;
	if (argc != 2)
		return (ft_printf("pls enter only the mapp as an argument\n"), 0);
	if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4)), ".ber", 4) != 0)
		return (ft_printf ("pls enter only a .ber map\n"), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("pas d'ouverture fichier inexistant?\n"), 0);
	temp = get_next_line(fd);
	while (temp)
	{
		check->h++;
		free(temp);
		temp = get_next_line(fd);
	}
	free (temp);
	temp = NULL;
	ft_printf("h = %d\n", check->h);
	if (check->h == 0)
		return (ft_printf("empty map\n"), 0);
	close(fd);
	return (1);
}

static	int	c_map(int argc, char **argv, t_check *check)
{
	int		i;
	char	*temp;
	int		len_temp;
	int		fd;

	i = 0;
	check->map = ft_calloc(check->h + 1, sizeof (char *));
	if (check->map == NULL)
		return (0);
	fd = open(argv[1], O_RDONLY);
	temp = get_next_line(fd);
	while (temp)
	{
		ft_printf ("temp %d = %s\n", i, temp);
		len_temp = ft_strlen(temp);
		if (len_temp > 0 && temp[len_temp - 1] == '\n')
			temp[len_temp - 1] = '\0';
		check->map[i] = ft_strdup(temp);
		free (temp);
		i++;
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_check	check;

	if (first_check(argc, argv, &check) == 0 || c_map(argc, argv, &check) == 0)
		return (1);
	i = 0;
	while (check.map[i])// debug while 
	{
		ft_printf ("map[%d] = %s\n", i, check.map[i]);
		i++;
	}
	ft_printf ("argc = %d\nargv = %s\n", argc, argv[1]);
	if (check_size_map(&check) == 0 || check_in_map(&check) == 0)
		return (ft_printf("error in map formatting\n"),
		free_map(&check), 1);
	if (flood_fil_launch(&check) == 0)
		return (ft_printf("fuck floodfill\n"), 
		free_map(&check), free_visited_map(&check), 1);
	i = 0;
	while (check.map[i])// debug while 
	{
		ft_printf ("2map[%d] = %s\n", i, check.map[i]);
		i++;
	}
	free_visited_map(&check);
	test(&check);
	return (0);
}
