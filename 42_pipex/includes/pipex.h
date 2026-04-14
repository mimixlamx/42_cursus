#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	char	**cmd1;
	char	**cmd2;
	char	*path_1;
	char	*path_2;
	int		fd_in;
	int		fd_out;
}	t_data;

int	open_fd(t_data *data, char **argv);

#endif
