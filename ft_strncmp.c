/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:49:11 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/14 11:55:48 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
#include <stdio.h>
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && n > 0 && s1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}
/*
int	main(void)
{
	int	rtn = 0;
	const char *str1 = "test123";
	const char *str2 = "";
	rtn = strncmpp(str1, str2, 2);
	printf ("rtn = %d\n", rtn);
	return (0);
}
*/
