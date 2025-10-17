/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:48:13 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/17 17:01:36 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

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
/*
int	main(void)
{
	char dest[50];
	const char *source = "aaa";
	unsigned long int len;

	len = ft_strlcpy(dest, source, 0);
	printf ("dest = %s \n", dest);
	printf ("len = %ld \n", len);
	if (len >= sizeof(dest))
		printf ("moins de bytes que a l'origine");
	else
		printf ("meme nombres de bites");
	return (0);
}*/
