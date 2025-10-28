/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:01:57 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 14:47:46 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
#include <stdio.h>
*/
#include <stddef.h>
/*
** need stddef for NULL
*/
char	*ft_strchr(const char *s, int c)
{
	unsigned char	ucc;

	ucc = (unsigned char)c;
	while (*s != ucc && *s)
		s++;
	if (*s == ucc)
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	const char *tkt = "teste";
	int a = '\0';
	char *rtn = ft_strchr(tkt, a);
	write (1, &a, 1);
	printf("string = %p\n", &rtn);
	return (0);
}
*/
