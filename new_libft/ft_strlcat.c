/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:03:43 by mbruyere          #+#    #+#             */
/*   Updated: 2026/04/20 14:39:48 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	lenof(const char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (dst[i])
		i++;
	if (size <= i)
		return (size + lenof(src));
	while (size - 1 > i && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	while (src[j])
	{
		j++;
		i++;
	}
	return (i);
}
