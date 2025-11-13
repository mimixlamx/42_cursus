/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_get_next_line.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/13 14:18:06 by mbruyere       #+#    #+#                */
/*   Updated: 2025/11/13 17:33:51 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_get_next_line.h"
#include <unistd.h>

char	*ft_get_next_line(int fd)
{
	static char	*buffer;
	char *small_buffer[BUFFER_SIZE];
	int rtn_read;

	rtn_read = read(fd, small_buffer, BUFFER_SIZE)
	if (ft(strchr(small_buffer, '\n') == NULL)
		
}
