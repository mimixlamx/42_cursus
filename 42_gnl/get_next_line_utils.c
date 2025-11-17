/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line_utils.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/17 18:02:18 by mbruyere       #+#    #+#                */
/*   Updated: 2025/11/17 18:10:12 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strchr(char *s, char c)
{
	unsigned char	ucc;

	ucc = (unsigned char)c;
	while (*s != ucc && *s)
		s++;
	if (*s == ucc)
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
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
