/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/13 14:18:06 by mbruyere       #+#    #+#                */
/*   Updated: 2025/11/17 18:11:24 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char		*ft_strchr(char *s, char c);
void		*ft_calloc(size_t nmemb, size_t size);
static char	*ft_fill_stash(char *stash, char *buffer, size_t size_buffer);
static char	*ft_rtn_value(char *stash);
static char	*ft_reduce_stash(char *stash);

char	*ft_get_next_line(int fd)
{
	static char	*stash = NULL;
	char		buffer[BUFFER_SIZE];
	size_t		size_buffer;
	char		*rtn;

	while (ft_strchr(buffer, '\n') == NULL)
	{
		size_buffer = read(fd, buffer, BUFFER_SIZE);
		if (size_buffer <= 0)
			return (NULL);
		stash = ft_fill_stash(stash, buffer, size_buffer);
	}
	rtn = ft_rtn_value(stash);
	stash = ft_reduce_stash(stash);
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
	rtn = ft_calloc(j, sizeof(char));
	j = 0;
	i++;
	while (stash[i + j])
	{
		rtn[j] = stash[i + j];
		j++;
	}
	rtn[j] = '\0';
	return (rtn);
	free(stash);
	stash = NULL;
}

static char	*ft_rtn_value(char *stash)
{
	int		i;
	char	*rtn;

	i = 0;
	while (stash[i] != '\n')
		i++;
	rtn = malloc (i * sizeof(char));
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
	while (i < BUFFER_SIZE)
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
static void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*array;
	size_t		cnt;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	cnt = 0;
	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	while ((nmemb * size) > cnt)
	{
		array[cnt] = 0;
		cnt++;
	}
	return (array);
}
static char	*ft_strchr(char *s, char c)
{
	unsigned char	ucc;

	ucc = (unsigned char)c;
	while (*s != ucc && *s)
		s++;
	if (*s == ucc)
		return ((char *)s);
	return (NULL);
}

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int		fd;
	char	*str_line;
	int		i;

	i= 0;
	fd = open("test_5_lignes.txt", O_RDONLY);
	while (i < 10)
	{
		str_line = ft_get_next_line(fd);
		printf("result ligne %d = %s", i, str_line);
		free(str_line);
		str_line = NULL;
		i++;
	}
	close(fd);
	return (0);
}*/
