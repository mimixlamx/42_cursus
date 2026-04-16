/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipex.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/14 14:11:35 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/16 15:52:35 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static int	ft_str_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static int	if_is_space_argv2(t_data *data, char **argv)
{
	data->cmd1 = ft_calloc(2, sizeof(char *));
	if (data->cmd1 == NULL)
		return (0);
	data->cmd1[0] = ft_strdup(argv[2]);
	if (data->cmd1[0] == NULL)
		return (0);
	data->cmd1[1] = NULL;
	return (1);
}

static int	if_is_space_argv3(t_data *data, char **argv)
{
	data->cmd2 = ft_calloc(2, sizeof(char *));
	if (data->cmd2 == NULL)
		return (0);
	data->cmd2[0] = ft_strdup(argv[3]);
	if (data->cmd2[0] == NULL)
		return (0);
	data->cmd2[1] = NULL;
	return (1);
}

int	parsing(t_data *data, char **argv)
{
	if (ft_str_is_space(argv[2]) == 1)
	{
		if (if_is_space_argv2(data, argv) == 0)
			return (0);
	}
	else
		data->cmd1 = ft_split(argv[2], ' ');
	if (!data->cmd1)
		return (0);
	if (ft_str_is_space(argv[3]) == 1)
	{
		if (if_is_space_argv3(data, argv) == 0)
			return (0);
	}
	else
		data->cmd2 = ft_split(argv[3], ' ');
	if (!data->cmd2)
		return (final_free(data), 0);
	if (data->cmd1[0] && data->cmd2[0])
		return (1);
	if (!data->cmd1[0])
		write(2, "permission denied: \n", 20);
	if (!data->cmd2[0])
		write(2, "permission denied: \n", 20);
	return (final_free(data), 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	data.path_1 = NULL;
	data.path_2 = NULL;
	data.envi = envp;
	if (argc != 5)
		return (write(2, "exec : ./pipex file1 cmd1 cmd2 file2\n", 37), 1);
	if (parsing(&data, argv) == 0)
		return (1);
	find_path(&data, envp);
	open_fd(&data, argv);
	if (WIFEXITED(data.status))
		return (final_free(&data), WEXITSTATUS(data.status));
	return (final_free(&data), 0);
}
