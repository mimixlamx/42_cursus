#include "pipex.h"

int	parsing(t_data *data, char** argv)
{
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	if (!data->cmd1 || !data->cmd2)
		return (ft_printf("error split\n"), 0);
	/* debug part
	int i; 
	i = 0;
	while (data->cmd1[i])
	{
		ft_printf("cmd1[%d] = %s\n", i, data->cmd1[i]);
		i++;
	}
	i = 0;
	while (data->cmd2[i])
	{
		ft_printf("cmd2[%d] = %s\n", i, data->cmd2[i]);
		i++;
	}
	*/
	return (1);
}

void	free_list(char **list)
{
	int i;

	i = 0;
	while(list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

int	path_for_1(t_data *data, char **list)
{
	char	*temp;
	char	*temp2;
	int i;

	i = 0;
	while (list[i])
	{
		temp = ft_strjoin(list[i], "/");
		temp2 = ft_strjoin(temp, data->cmd1[0]);
		if (access(temp2, X_OK) == 0)
		{
			data->path_1 = ft_strdup(temp2);
			return(free(temp), free(temp2), 1);
		}
		i++;
		free(temp);
		free (temp2);
	}
	return (0);
}

int	path_for_2(t_data *data, char **list)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	while (list[i])
	{
		temp = ft_strjoin(list[i], "/");
		temp2 = ft_strjoin(temp, data->cmd2[0]);
		if (access(temp2, X_OK) == 0)
		{
			data->path_2 = ft_strdup(temp2);
			return(free(temp), free(temp2), 1);
		}
		i++;
		free(temp);
		free (temp2);
	}
	return (0);
}

int	find_path(t_data *data, char **envp)
{
	char *temp;
	int		i;
	char	**list;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=" , 5) != 0)
		i++;
	if (!envp[i])
		return (ft_printf("no path\n"), 0);
	temp = envp[i] + 5;
	list = ft_split(temp, ':');
	if (path_for_1(data, list) == 0 || path_for_2(data, list) == 0)
		return (free_list(list), 0);
	return (free_list(list), 1);
}


void final_free(t_data *data)
{
	int i;

	i = 0;
	while(data->cmd1[i])
	{
		free(data->cmd1[i]);
		i++;
	}
	free(data->cmd1);
	i = 0;
	while(data->cmd2[i])
	{
		free(data->cmd2[i]);
		i++;
	}
	free(data->cmd2);
	free(data->path_1);
	free(data->path_2);
}

int	main(int argc, char **argv, char **envp)
{
	t_data data;
	if (argc != 5)
		return (ft_printf("4 arguments svp./pipex file1 cmd1 cmd2 file2\n"), 1);
	ft_printf("argv[2] = %s, argv[3] = %s\n", argv[2], argv[3]);
	if (parsing(&data, argv) == 0 || find_path(&data, envp) == 0)
		return (1);
	ft_printf("path_1 = %s\n", data.path_1);
	ft_printf("path_2 = %s\n", data.path_2);
	return (final_free(&data), 0);
}

