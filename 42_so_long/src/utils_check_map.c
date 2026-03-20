/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   utils_check_map.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/18 13:57:22 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/20 16:58:33 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	first_check(int argc, char **argv, t_check *check)
{
	char	*temp;
	int		fd;

	check->h = 0;
	if (argc != 2)
		return (ft_printf("Error\npls enter only the mapp as argument\n"), 0);
	if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4)), ".ber", 4) != 0)
		return (ft_printf ("Error\npls enter only a .ber map\n"), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\n no oppening did the file exist?\n"), 0);
	temp = get_next_line(fd);
	while (temp)
	{
		check->h++;
		free(temp);
		temp = get_next_line(fd);
	}
	free (temp);
	temp = NULL;
	if (check->h == 0)
		return (ft_printf("Error\nempty map\n"), 0);
	close(fd);
	return (1);
}

int	c_map(char **argv, t_check *check)
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

int	check_size_map(t_check	*check)
{
	int	i;

	i = 1;
	check->w = ft_strlen(check->map[0]);
	while (check->map[i] && check->w == (int)ft_strlen(check->map[i]))
		i++;
	if (i != check->h)
		return (ft_printf("Error\nin size line len_0 = %d vs len_%d = %d\n",
				check->w, i, (int)ft_strlen(check->map[i])), 0);
	if (check->w == check->h)
		return (ft_printf("Error\nsquare map\n"), 0);
	else
		return (1);
}
