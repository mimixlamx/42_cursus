/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:51:01 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/14 11:53:12 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tkt;
	unsigned char		ucc;

	ucc = (const unsigned char)c;
	tkt = (const unsigned char *)s;
	
	while (n > 1 && *tkt != ucc)
	{
		n--;
		tkt++;
	}
	if (*tkt == ucc)
		return ((void *)tkt);
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
