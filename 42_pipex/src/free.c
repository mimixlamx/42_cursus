/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   free.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/14 14:15:06 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/15 15:20:01 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free (list[i]);
		i++;
	}
	free(list);
}

static void	free_path(t_data *data)
{
	if (data->path_1)
		free(data->path_1);
	if (data->path_2)
		free(data->path_2);
}

void	final_free(t_data *data)
{
	int	i;

	i = 0;
	if (data->cmd1)
	{
		while (data->cmd1[i])
		{
			free(data->cmd1[i]);
			i++;
		}
		free(data->cmd1);
	}
	i = 0;
	if (data->cmd2)
	{
		while (data->cmd2[i])
		{
			free(data->cmd2[i]);
			i++;
		}
		free(data->cmd2);
	}
	free_path(data);
}
