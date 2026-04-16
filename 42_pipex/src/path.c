/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   path.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/16 15:49:35 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/16 16:12:04 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static int	path_for_1(t_data *data, char **list)
{
	char	*temp;
	char	*temp2;
	int		i;

	if (access(data->cmd1[0], X_OK) == 0)
	{
		data->path_1 = ft_strdup(data->cmd1[0]);
		return (1);
	}
	i = 0;
	while (list[i])
	{
		temp = ft_strjoin(list[i], "/");
		temp2 = ft_strjoin(temp, data->cmd1[0]);
		if (access(temp2, X_OK) == 0)
		{
			data->path_1 = ft_strdup(temp2);
			return (free(temp), free(temp2), 1);
		}
		i++;
		free (temp);
		free (temp2);
	}
	return (0);
}

static int	path_for_2(t_data *data, char **list)
{
	int		i;
	char	*temp;
	char	*temp2;

	if (access(data->cmd2[0], X_OK) == 0)
	{
		data->path_2 = ft_strdup(data->cmd2[0]);
		return (1);
	}
	i = 0;
	while (list[i])
	{
		temp = ft_strjoin(list[i], "/");
		temp2 = ft_strjoin(temp, data->cmd2[0]);
		if (access(temp2, X_OK) == 0)
		{
			data->path_2 = ft_strdup(temp2);
			return (free (temp), free (temp2), 1);
		}
		i++;
		free (temp);
		free (temp2);
	}
	return (0);
}

int	find_path(t_data *data, char **envp)
{
	char	*temp;
	int		i;
	char	**list;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (0);
	temp = envp[i] + 5;
	list = ft_split(temp, ':');
	path_for_1(data, list);
	path_for_2(data, list);
	return (free_list(list), 1);
}
