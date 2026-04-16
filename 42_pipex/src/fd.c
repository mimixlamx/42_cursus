/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   fd.c                                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/14 14:06:24 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/16 16:09:03 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_fd(t_data *data, char **argv)
{
	data->fd_in = open(argv[1], O_RDONLY);
	data->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_in < 0)
		perror(argv[1]);
	if (data->fd_out < 0)
		perror(argv[4]);
	if (pipe(data->pipefd) == -1)
	{
		perror("pipe");
		exit (1);
	}
	fork_process_1(data);
}

void	close_all_fd(t_data *data)
{
	close(data->fd_out);
	close(data->pipefd[0]);
	close(data->fd_in);
	close(data->pipefd[1]);
}
