/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   fd.c                                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/14 14:06:24 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/15 16:27:47 by mbruyere       ########   odam.nl        */
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

void	fork_process_1(t_data *data)
{
	int	temp;
	int	rtnpid;
	data->forked1 = fork ();
	if (data->forked1 == 0)
	{
		if (data->fd_in >= 0)
		{
			dup2(data->fd_in, 0);
			dup2(data->pipefd[1], 1);
			close_all_fd(data);
			if (data->path_1 == NULL && !ft_strchr(data->cmd1[0], '/'))
			{
				write(2, data->cmd1[0], ft_strlen(data->cmd1[0]));
				write(2, ": command not found", 20);
				write(2, "\n", 1);
				final_free(data);
				exit(127);
			}
			else if (ft_strchr (data->cmd1[0], '/'))
				data->path_1 = ft_strdup(data->cmd1[0]);
			execve(data->path_1, data->cmd1, data->envi);
			perror(data->cmd1[0]);
			final_free(data);
			if (errno == EACCES)
				exit(126);
			else
				exit(127);
		}
		close_all_fd(data);
		final_free(data);
		exit(1);
	}
	else if (data->forked1 > 0)
	{
		fork_process_2(data);
		close_all_fd(data);
		rtnpid = waitpid(-1, &temp, 0);
		if (data->forked2 == rtnpid)
			data->status = temp;
		rtnpid = waitpid(-1, &temp, 0);
		if (data->forked2 == rtnpid)
			data->status = temp;
	}
	else
		perror("fork");
}

void	fork_process_2(t_data *data)
{
	data->forked2 = fork();
	if (data->forked2 == 0)
	{
		if (data->fd_out >= 0)
		{
			dup2(data->fd_out, 1);
			dup2(data->pipefd[0], 0);
			close_all_fd(data);
			if (data->path_2 == NULL && !ft_strchr(data->cmd2[0], '/'))
			{
				write(2, data->cmd2[0], ft_strlen(data->cmd2[0]));
				write(2, ": command not found", 20);
				write(2, "\n", 1);
				final_free(data);
				exit(127);
			}
			else if (ft_strchr (data->cmd2[0], '/'))
				data->path_2 = ft_strdup(data->cmd2[0]);
			execve(data->path_2, data->cmd2, data->envi);
			perror(data->cmd2[0]);
			final_free(data);
			if (errno == EACCES)
				exit(126);
			else
				exit(127);
		}
		close_all_fd(data);
		final_free(data);
		exit(1);
	}
	else if (data->forked2 < 0)
		perror("fork");
}
