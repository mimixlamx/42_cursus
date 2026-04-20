/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:51:01 by mbruyere          #+#    #+#             */
/*   Updated: 2026/04/20 14:34:45 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
