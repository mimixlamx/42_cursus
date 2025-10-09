/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:57:54 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/03 09:58:17 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
/*
#include <stdio.h>
*/
void	*memcpy(void *dest, const void *src, size_t n);

void	*memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (d);
}
/*
int	main(void)
{
	char src[10] = "123456789";
	char dest[10] = "ABCDEFGHI";
	memcpy(dest, src, 5);
	printf("string dest = %s", dest);
	return (0);
}*/
