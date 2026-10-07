/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:48:13 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 16:54:56 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
** need stddef for size_t
*/

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
