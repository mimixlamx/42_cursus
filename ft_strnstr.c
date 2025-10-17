/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:00:46 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/17 15:56:31 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	cnt;

	cnt = 0;
	if (*little == '\0')
		return ((char *)big);
	while (len > 0 && *big)
	{
		while (*big == *little && *little && len > 0)
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
	size_t	le;
	char	*rtn;

	b = "abcdef";
	l = "abc\375xx";
	le = 30;
	rtn = ft_strnstr(b, l, le);
	printf("rtn = %s\n", rtn);
	return (0);
}
*/
