/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipex.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/14 14:11:35 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/14 15:59:30 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// is space pour verifier sila str est 100% des espace et donc envoyer ca en commande
int	parsing(t_data *data, char **argv)
{
	data->cmd1 = ft_split(argv[2], ' ');
	if (!data->cmd1)
		return (0);
	data->cmd2 = ft_split(argv[3], ' ');
	if (!data->cmd2)
		return (final_free(data), 0);
	if (data->cmd1[0] && data->cmd2[0])
		return (1);
	if (!data->cmd1[0])
		write(2,"zsh: permission denied: \n", 25);
	if(!data->cmd2[0])
		write(2,"zsh: permission denied: \n", 25);
	return (final_free(data), 0);
}

int	path_for_1(t_data *data, char **list)
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

int	path_for_2(t_data *data, char **list)
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
		return (ft_printf("no path\n"), 0);
	temp = envp[i] + 5;
	list = ft_split(temp, ':');
	path_for_1(data, list);
	path_for_2(data, list);
	return (free_list(list), 1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	data.path_1 = NULL;
	data.path_2 = NULL;
	data.envi = envp;
	if (argc != 5)
		return (ft_printf("4 arguments svp./pipex file1 cmd1 cmd2 file2\n"), 1);
	if (parsing(&data, argv) == 0)
		return (1);
	find_path(&data, envp);
	open_fd(&data, argv);
	return (final_free(&data), 0);
}
