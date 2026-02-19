#include "so_long.h"

void	free_map(t_check *check)
{
	int	i;

	i = 0;
	while (i < check->h)
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
	while (i < check->h)
	{
		free(check->visited_map[i]);
		i++;
	}
	free(check->visited_map);
}
