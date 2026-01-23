/*
 ** file dedicated to check the map on so-long project 
*/
#include "libft.h"
/*
 ** pour include la lib
 ** voir pour toutmettre dansla lib gn printf etc
*/
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> // to be deleted
int	main(int argc, char **argv)
{
	char	**map;
	char	*temp;
	int		i;
	int		fd;

	i = 0;
	if (argc != 2) 
		return (printf("pls enter only the mapp as an argument\n"), 0);// attention remplacer par ftprintf
	if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4)),".ber", 4) != 0)
		return (printf ("pls enter only a .ber mapp\n"), 0);// idem
	fd = open(argv[1], O_RDONLY);
	while ((temp = get_next_line(fd)) != NULL)
		i++;
	printf("i = %d\n", i);
	map = ft_calloc(i + 1, sizeof (char*));
	close(fd);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while ((temp = get_next_line(fd)) != NULL)
	{
		printf ("temp %d = %s\n", i, temp);
		map[i] = ft_strdup(temp);
		i++;
	}
	close(fd);
	i = 0;
	while (map[i])
	{
		printf ("map = %s\n", map[i]);
		i++;
	}
	printf ("argc = %d\nargv = %s\n", argc, argv[1]);
	return (0);
}
