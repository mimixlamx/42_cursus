#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	char	**cmd1;
	char	**cmd2;
	char	*path_1;
	char	*path_2;
}	t_data;

void	sa(t_data *data);

#endif
