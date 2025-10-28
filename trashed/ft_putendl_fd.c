/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:49:05 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 13:57:02 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
/*
** need unistd for the write
*/
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}
/*
int	main(void)
{
	ft_putendl_fd("tkt1234/", 1);
	return (0);
}*/
