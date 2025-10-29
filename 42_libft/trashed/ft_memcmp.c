/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:57:36 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 14:17:30 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
#include <stddef.h>
/*
** need stddef for the size_t
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cucs1;
	const unsigned char	*cucs2;

	if (n == 0)
		return (0);
	cucs1 = (const unsigned char *)s1;
	cucs2 = (const unsigned char *)s2;
	while (*cucs1 == *cucs2 && n > 1)
	{
		cucs1++;
		cucs2++;
		n--;
	}
	return (*cucs1 - *cucs2);
}
/*
int	main(void)
{
	char str1[10] = "test1234/";
	char str2[10] = "test1234/";
	int size = 10;
	int rtn = memcmpp(str1, str2, size);
	printf ("rtn value = %d\n", rtn);
	return (0);
}
*/
