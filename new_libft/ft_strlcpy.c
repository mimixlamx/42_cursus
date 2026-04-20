/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:48:13 by mbruyere          #+#    #+#             */
/*   Updated: 2026/04/20 14:40:12 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	tkt;

	tkt = 0;
	while (size > 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
		tkt++;
	}
	while (*src)
	{
		src++;
		tkt++;
	}
	if (size == 0)
		return (tkt);
	*dst = '\0';
	return (tkt);
}
