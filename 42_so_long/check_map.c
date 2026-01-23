/*
 ** file dedicated to check the map on so long project 
*/
#include "libft.h"
/*
 ** to include the libft
 ** voir pour toutmettre dansla lib gn printf etc
*/
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> // to be deleted

int	check_in_map(int size, char **map)
{
	
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
		return (printf("error in size of a line\n i = %d, size = %d", i, size), 0);
	if (len_0 == size)
		return (printf("error square map\n"),0);
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
		printf ("temp %d = %s", i, temp);
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
