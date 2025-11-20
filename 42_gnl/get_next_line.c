/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/13 14:18:06 by mbruyere       #+#    #+#                */
/*   Updated: 2025/11/20 17:05:44 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char		*ft_strchr(char *s, char c);
void		*ft_calloc(size_t nmemb, size_t size);
static char	*ft_fill_stash(char *stash, char *buffer, size_t size_buffer);
static char	*ft_rtn_value(char *stash);
static char	*ft_reduce_stash(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*buffer;
	size_t		size_buffer;
	char		*rtn;

	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (stash == NULL || ft_strchr(stash, '\n') == NULL)
	{
		size_buffer = read(fd, buffer, BUFFER_SIZE);
		if (size_buffer <= 0)
			return (free(buffer), NULL);
		stash = ft_fill_stash(stash, buffer, size_buffer);
	}
	rtn = ft_rtn_value(stash);
	stash = ft_reduce_stash(stash);
	free(buffer);
	return (rtn);
}

static char	*ft_reduce_stash(char *stash)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	j = 0;
	while (stash[i] != '\n')
		i++;
	while (stash[i + j])
		j++;
	if (j == 1)
		return (free(stash), NULL);
	rtn = ft_calloc(j, sizeof(char));
	if (rtn == NULL)
		return (NULL);
	j = 0;
	i++;
	while (stash[i + j])
	{
		rtn[j] = stash[i + j];
		j++;
	}
	rtn[j] = '\0';
	free(stash);
	return (rtn);
}

static char	*ft_rtn_value(char *stash)
{
	int		i;
	char	*rtn;

	i = 0;
	while (stash[i] != '\n')
		i++;
	rtn = ft_calloc(i + 2, sizeof(char));
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\n')
	{
		rtn [i] = stash[i];
		i++;
	}
	rtn[i] = '\n';
	return (rtn);
}

static char	*ft_fill_stash(char *stash, char *buffer, size_t size_buffer)
{
	size_t	len;
	char	*rtn;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	len = 0;
	while (stash != NULL && stash[len])
		len++;
	rtn = ft_calloc(len + size_buffer + 1, sizeof(char));
	if (rtn == NULL)
		return (NULL);
	while (i < size_buffer)
	{
		while (j < len)
		{
			rtn[j] = stash[j];
			j++;
		}
		rtn[len + i] = buffer[i];
		i++;
	}
	return (rtn);
}
/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int		fd;
	char	*str_line;
	int		i;

	i= 1;
	fd = open("test_16_line_one_word.txt", O_RDONLY);
	while (i < 20)
	{
		str_line = get_next_line(fd);
		printf("result ligne %d = %s", i, str_line);
		free(str_line);
		str_line = NULL;
		i++;
	}
	close(fd);
	return (0);
}*/
