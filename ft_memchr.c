/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:51:01 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 13:57:46 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/

#include <stddef.h>
/*
** need stddef for the size_t
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*cucs;
	unsigned char		cucc;

	cucc = (const unsigned char)c;
	cucs = (const unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (n > 1 && *cucs != cucc)
	{
		n--;
		cucs++;
	}
	if (*cucs == cucc)
		return ((void *)cucs);
	return (NULL);
}
/*
int	main(void)
{
	char s[10] = "bonjourno";
	int c = 'n';
	int n = 2;
	unsigned char *rtn = ft_memchr(s, c, n);
	printf ("rtn = %s \n", rtn);
	return(0);
}*/
