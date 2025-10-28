/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:30:24 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 14:35:32 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
/*
** need stddef for the size_t
*/
/*
#include <stdio.h>
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ucs;

	ucs = (unsigned char *)s;
	while (n > 0)
	{
		*ucs = c;
		n--;
		ucs++;
	}
	return (s);
}
/*
int	main(void)
{
	char buffer[10];
	memset(buffer, 'a', 5);
	printf("string = %s", buffer);
	return (0);
}*/
