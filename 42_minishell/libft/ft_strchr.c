/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:01:57 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 16:53:46 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
** need stddef for NULL
*/
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
