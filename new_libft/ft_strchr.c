/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:01:57 by mbruyere          #+#    #+#             */
/*   Updated: 2026/04/20 14:38:29 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ucc;

	ucc = (unsigned char)c;
	while (*s != ucc && *s)
		s++;
	if (*s == ucc)
		return ((char *)s);
	return (NULL);
}
