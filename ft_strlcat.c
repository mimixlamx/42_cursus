/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:03:43 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/16 12:44:23 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	tkt;

	tkt = 0;
	while (*dst && size > 0)
	{
		tkt++;
		dst++;
		size--;
	}
	while (size > 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		tkt++;
		size--;
	}
	*dst = '\0';
	return (tkt);
}
/*
int	main(void)
{
	char	dest[10];
	char	*source = "012345678910";
	int		len;

	dest[5] = 'a';
	len = ft_strlcat(dest, source, sizeof(dest));
	printf("len = %d \n", len);
	printf("concat = %s \n", dest);
	return(0);
}*/
