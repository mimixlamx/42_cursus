#include "so_long.h"

void	free_map(t_check *check)
{
	int	i;

	printf ("free map rn\n");
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

	printf ("free visited map rn\n");
	i = 0;
	while (check->visited_map && check->visited_map[i])
	{
		free(check->visited_map[i]);
		i++;
	}
	free(check->visited_map);
}
