/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   fd.c                                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/14 14:06:24 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/14 16:13:12 by mbruyere       ########   odam.nl        */
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
	data->forked1 = fork ();
	if (data->forked1 == 0)
	{
		if (data->fd_in >= 0)
		{
			dup2(data->fd_in, 0);
			dup2(data->pipefd[1], 1);
			close_all_fd(data);
			if (data->path_1 == NULL)
			{
				write(2, "zsh: command not found: ", 25);
				write(2, data->cmd1[0], ft_strlen(data->cmd1[0]));
				write(2, "\n", 1);
				exit(127);
			}
			execve(data->path_1, data->cmd1, data->envi);
			perror(data->cmd1[0]);
			exit(1);
		}
	}
	else if (data->forked1 > 0)
	{
		fork_process_2(data);
		close_all_fd(data);
		waitpid(data->forked1, NULL, 0);
		waitpid(data->forked2, NULL, 0);
	}
	else
		perror("fork");
}

void	fork_process_2(t_data *data)
{
	data->forked2 = fork();
	if (data->forked2 == 0)
	{
		close(data->pipefd[1]);
		close(data->fd_in);
		dup2(data->fd_out, 1);
		dup2(data->pipefd[0], 0);
		close(data->fd_out);
		close(data->pipefd[0]);
		if (data->path_2 == NULL)
		{
			write(2, "zsh: command not found: ", 25);
			write(2, data->cmd2[0], ft_strlen(data->cmd2[0]));
			write(2, "\n", 1);
			exit(127);
		}
		execve(data->path_2, data->cmd2, data->envi);
		perror(data->cmd2[0]);
		exit(1);
	}
	else if (data->forked2 < 0)
		perror("fork");
}
