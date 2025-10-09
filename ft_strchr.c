/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:01:57 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/03 10:03:03 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
#include <stddef.h>

char	*strchr(const char *s, int c);

char	*strchr(const char *s, int c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	const char *tkt = "mengea";
	int a = 'a';
	char *rtn = strchrr(tkt, a);
	printf("string = %s\n", rtn);
	return (0);
}
*/
