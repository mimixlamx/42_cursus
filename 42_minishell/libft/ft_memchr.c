/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:51:01 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 16:50:59 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
** need stddef for the size_t
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*cucs;
	unsigned char		cucc;

	cucc = (const unsigned char)c;
	cucs = (const unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (n > 1 && *cucs != cucc)
	{
		n--;
		cucs++;
	}
	if (*cucs == cucc)
		return ((void *)cucs);
	return (NULL);
}
