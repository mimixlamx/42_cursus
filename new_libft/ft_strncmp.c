/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:49:11 by mbruyere          #+#    #+#             */
/*   Updated: 2026/04/20 14:41:08 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	ucs1 = (unsigned char *)s1;
	ucs2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*ucs1 == *ucs2 && *ucs1 && n > 1)
	{
		ucs1++;
		ucs2++;
		n--;
	}
	return (*ucs1 - *ucs2);
}
