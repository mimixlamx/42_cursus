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
int		lenof(const char *src);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	tkt;
	size_t	tkt2;

	tkt2 = 0;
	tkt = 0;
	while (dst[tkt])
		tkt++;
	if (size <= tkt)
		return (size + lenof(src));
	while (size - 1 > tkt && src[tkt2])
	{
		dst[tkt] = src[tkt2];
		tkt++;
		tkt2++;
	}
	dst[tkt] = '\0';
	while (src[tkt2])
	{
		tkt2++;
		tkt++;
	}
	return (tkt);
}

int	lenof(const char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

/*
int	main(void)
{
	char	dest[4] = "";
	char	*source = "thx to ntoniolo for this test !";
	int		len;

	len = ft_strlcat(dest, source, 4);
	printf("len = %d \n", len);
	printf("concat = %s \n", dest);
	return(0);
}*/
