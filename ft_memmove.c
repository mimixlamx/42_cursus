/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:00:48 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/24 14:09:13 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n);
void	reversemove(unsigned char *d, const unsigned char *s, size_t n);
void	move(unsigned char *d, const unsigned char *s, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
		ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}
/*
void	move(unsigned char *d, const unsigned char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
}

void	reversemove(unsigned char *d, const unsigned char *s, size_t n)
{
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
}
*/
/*
int	main(void)
{
	char src[10] = "123456789";
	char dest[10] = "ABCDEFGHI";
	memmovee(dest, src, 5);
	printf("string dest = %s", dest);
	return (0);
}*/
