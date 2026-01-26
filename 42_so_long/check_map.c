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

int	check_in_map(int size, char **map)
{
	int	i;
	int	len_0;
	int	y;
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	y = 0;
	i = 0;
	len_0 = ft_strlen(map[0]);
	while (i < size)
	{
		if (i == 0 || i == size - 1)
		{
		printf ("first or last line i = %d\n", i);
			while (y < len_0)
			{
				if (map[i][y] == '1')
					y++;
				else
					return (printf("error in line %d not only 1\n", i), 0);
			}
			y = 0;
		}
		else
		{
			printf ("inside lines i =%d y = %d\n", i, y);
			if (map[i][0] == '1' && map[i][len_0 - 1] == '1')
				y++;
			else
				return (printf("error border line map[%d]\n", i));
			while (y > 0 && y <= len_0 - 2)
			{
				if (map[i][y] == '0' || map[i][y] == 'P' || map[i][y] == 'E' || map[i][y] == 'C')
				{
					if (map[i][y] == 'P')
						p++;
					else if (map[i][y] == 'E')
						e++;
					else if (map[i][y] == 'C')
						c++;
					y++;
				}
				else
					return (printf("error char not ok in map %c in position [%d][%d] char %c\n", map[i][y], i, y, map[i][y]), 0);
			}
			y = 0;
		}
		i++;
	}
	if (p > 1 || p == 0)
		return (printf("1 player needed, now %d\n", p), 0);
	if (e > 1 || e == 0)
		return (printf("1 exit needed, now %d\n", e), 0);
	if (c == 0) 
		return (printf("1 collectible  needed, now %d\n", c), 0);
	else
		return (printf("no error in mapp"), 1);
}

int	check_size_map(int size, char **map)
{
	int	i;
	int	len_0;

	i = 1;
	len_0 = ft_strlen(map[0]);
	while (map[i] && len_0 == ft_strlen(map[i]))
	{
		printf ("len_0 = %d\n", len_0);
		printf ("len_%d= %ld\n", i, ft_strlen(map[i]));
		i++;
	}
	if (i != size)
		return (printf("error in size of a line\n i = %d, size = %d\n", i, size), 0);
	if (len_0 == size)
		return (printf("error square map\n"),0);
	else
		return (printf("'no error on size mapp\n"),1);
}

int	main(int argc, char **argv)
{
	char	**map;
	char	*temp;
	int		size;
	int		i;
	int		fd;
	int		len_temp;

	i = 0;
	size = 0;
	if (argc != 2)
		return (printf("pls enter only the mapp as an argument\n"), 0);// attention remplacer par ftprintf
	if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4)),".ber", 4) != 0)
		return (printf ("pls enter only a .ber map\n"), 0);// idem
	fd = open(argv[1], O_RDONLY);
	while ((temp = get_next_line(fd)) != NULL)
		size++;
	printf("size = %d\n", i);
	map = ft_calloc(size + 1, sizeof (char*));
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while ((temp = get_next_line(fd)) != NULL)
	{
		printf ("temp %d = %s\n", i, temp);
		len_temp = ft_strlen(temp);
		if (len_temp > 0 && temp[len_temp - 1] == '\n')
			temp[len_temp - 1] = '\0';
		map[i] = ft_strdup(temp);
		i++;
	}
	close(fd);
	i = 0;
	while (map[i])
	{
		printf ("map[%d] = %s\n", i, map[i]);
		i++;
	}
	printf ("argc = %d\nargv = %s\n", argc, argv[1]);
	if (check_size_map(size, map) == 0 || check_in_map(size, map) == 0)
		return(printf("error in map formatting\n"), 1);
	return (0);
}
