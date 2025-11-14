/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_get_next_line.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/13 14:18:06 by mbruyere       #+#    #+#                */
/*   Updated: 2025/11/14 16:55:30 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_get_next_line.h"
#include <unistd.h>

static char	*ft_strchr(char *s, char c);
static char	*ft_fill_buff(char *buffer, char *small_buffer);

char	*ft_get_next_line(int fd)
{
	static char	*stash = NULL;
	char small_buffer[BUFFER_SIZE];
	int rtn_read;

	while (ft_strchr(small_buffer, '\n') == NULL)
	{
		rtn_read = read(fd, small_buffer, BUFFER_SIZE);
		stash = ft_fill_buff(stash, small_buffer);
	}
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

static char	*ft_fill_buff(char *stash, char *small_buffer);
{
	
}
