/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:50:07 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/03 09:50:37 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
#include <stddef.h>

char	*strrchr(const char *s, int c);

char	*strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	while (*s != c && len > 0)
		s--;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	const char *tkt = "amenegea";
	int a = 'a';
	char *rtn = strrchrr(tkt, a);
	printf("string = %s\n", rtn);
	return (0);
}
*/
