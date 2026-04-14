#include "pipex.h"
int	open_fd(t_data *data, char **argv)
{
	data->fd_in = open(argv[1], O_RDONLY);
	data->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_in < 0)
		perror(argv[1]);
	if (data->fd_out < 0)
		perror(argv[4]);
	return (1);
}
