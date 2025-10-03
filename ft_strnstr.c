/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:00:46 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/03 10:11:14 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
#include <stddef.h>

char	*strnstr(const char *big, const char *little, size_t len);

char	*strnstr(const char *big, const char *little, size_t len)
{
	int	cnt;

	cnt = 0;
	if (*little == '\0')
		return ((char *)big);
	while (len > 0 && *big)
	{
		while (*big == *little && *little)
		{
			big++;
			little++;
			cnt++;
			len--;
		}
		if (*little && len > 0 && *big)
		{
			little = little - cnt;
			big = big - cnt + 1;
			len = len + cnt + -1;
		}
		else if (*little == '\0')
			return ((char *)big - cnt);
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*b;
	char	*l;
	int		le;
	char	*rtn;

	b = "123atkt12d";
	l = "d";
	le = 20;
	rtn = strnstrr(b, l, le);
	printf("rtn = %s\n", rtn);
	return (0);
}
*/
