/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:00:48 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/03 10:01:44 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
#include <stddef.h>

void	*memmove(void *dest, const void *src, size_t n);

void	*memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	char				tmp[10];

	*tmp = '\0';
	d = dest;
	s = src;
	while (n > 0)
	{
		*tmp = *s;
		*d = *tmp;
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
	memmovee(dest, src, 5);
	printf("string dest = %s", dest);
	return (0);
}*/
