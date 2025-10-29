/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:03:43 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 15:29:08 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
#include <stddef.h>
/*
** need stddef for size_t
*/
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
