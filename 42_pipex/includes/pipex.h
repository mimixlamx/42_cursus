/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipex.h                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/14 14:16:28 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/16 16:12:43 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_data
{
	char	**envi;
	char	**cmd1;
	char	**cmd2;
	char	*path_1;
	char	*path_2;
	int		fd_in;
	int		fd_out;
	int		pipefd[2];
	int		forked1;
	int		forked2;
	int		status;
}	t_data;

void	free_list(char **list);
void	final_free(t_data *data);
void	open_fd(t_data *data, char **argv);
void	close_all_fd(t_data *data);
void	fork_process_1(t_data *data);
int		find_path(t_data *data, char **envp);

#endif
