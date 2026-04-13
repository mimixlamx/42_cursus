/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:57:36 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 16:51:12 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
** need stddef for the size_t
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cucs1;
	const unsigned char	*cucs2;

	if (n == 0)
		return (0);
	cucs1 = (const unsigned char *)s1;
	cucs2 = (const unsigned char *)s2;
	while (*cucs1 == *cucs2 && n > 1)
	{
		cucs1++;
		cucs2++;
		n--;
	}
	return (*cucs1 - *cucs2);
}
