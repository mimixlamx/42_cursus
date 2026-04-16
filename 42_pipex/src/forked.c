/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   forked.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/16 16:08:32 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/16 16:11:10 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static void	if_children_process_2(t_data *data)
{
	int	err;

	dup2(data->fd_out, 1);
	dup2(data->pipefd[0], 0);
	close_all_fd(data);
	if (data->path_2 == NULL && !ft_strchr(data->cmd2[0], '/'))
	{
		write(2, "command not found: ", 19);
		write(2, data->cmd2[0], ft_strlen(data->cmd2[0]));
		write(2, "\n", 1);
		final_free(data);
		exit(127);
	}
	else if (ft_strchr (data->cmd2[0], '/'))
		data->path_2 = ft_strdup(data->cmd2[0]);
	execve(data->path_2, data->cmd2, data->envi);
	err = errno;
	perror(data->cmd2[0]);
	final_free(data);
	if (err == ENOENT)
		exit(127);
	else if (err == EACCES)
		exit(126);
	else
		exit(1);
}

static void	fork_process_2(t_data *data)
{
	data->forked2 = fork();
	if (data->forked2 == 0)
	{
		if (data->fd_out >= 0)
		{
			if_children_process_2(data);
		}
		close_all_fd(data);
		final_free(data);
		exit(1);
	}
	else if (data->forked2 < 0)
		perror("fork");
}

static void	if_children_process_1(t_data *data)
{
	int	err;

	dup2(data->fd_in, 0);
	dup2(data->pipefd[1], 1);
	close_all_fd(data);
	if (data->path_1 == NULL && !ft_strchr(data->cmd1[0], '/'))
	{
		write(2, "command not found: ", 19);
		write(2, data->cmd1[0], ft_strlen(data->cmd1[0]));
		write(2, "\n", 1);
		final_free(data);
		exit(127);
	}
	else if (ft_strchr (data->cmd1[0], '/'))
		data->path_1 = ft_strdup(data->cmd1[0]);
	execve(data->path_1, data->cmd1, data->envi);
	err = errno;
	perror(data->cmd1[0]);
	final_free(data);
	if (err == ENOENT)
		exit(127);
	else if (err == EACCES)
		exit(126);
	else
		exit(1);
}

static void	if_parent_process_1(t_data *data)
{
	int	temp;
	int	rtnpid;

	fork_process_2(data);
	close_all_fd(data);
	rtnpid = waitpid(-1, &temp, 0);
	if (data->forked2 == rtnpid)
		data->status = temp;
	rtnpid = waitpid(-1, &temp, 0);
	if (data->forked2 == rtnpid)
		data->status = temp;
}

void	fork_process_1(t_data *data)
{
	data->forked1 = fork ();
	if (data->forked1 == 0)
	{
		if (data->fd_in >= 0)
		{
			if_children_process_1(data);
		}
		close_all_fd(data);
		final_free(data);
		exit(1);
	}
	else if (data->forked1 > 0)
	{
		if_parent_process_1(data);
	}
	else
		perror("fork");
}
