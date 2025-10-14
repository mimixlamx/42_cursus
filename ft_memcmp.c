/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:57:36 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/14 11:53:31 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;

	t1 = s1;
	t2 = s2;
	while (*t1 == *t2 && n > 1)
	{
		t1++;
		t2++;
		n--;
	}
	return (*t1 - *t2);
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
