#include "libft.h"
#include "so_long.h"

int	flood_fil_launch(int size, int x, int y, int c, char **map)
{
	char	visited_map;
	int		found_c;
	int		found_e;
	int		i;

	i = 0;
	found_c = 0;
	found_e = 0;
	visited_map = ft_calloc(size + 1, sizeof (char*));
	while (i < size - 1)
	{
		visited_map[i] = ft_strdup(map[i]);
		printf("visited_map[i] = %s\n", visited_map[i]);
		i++;
	}
	return(0);
}
