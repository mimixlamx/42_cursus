/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:50:07 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 16:56:00 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
/*
** need stddef for NULL
*/
char	*ft_strrchr(const char *s, int c)
{
	int					len;
	unsigned char		ucc;
	unsigned char		*cucs;

	cucs = (unsigned char *)s;
	ucc = (unsigned char)c;
	len = 0;
	while (cucs[len])
		len++;
	while (cucs[len] != ucc && len > 0)
		len--;
	if (cucs[len] == ucc)
		return ((char *)&cucs[len]);
	return (NULL);
}
