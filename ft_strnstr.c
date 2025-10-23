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
size_t	lenfc(unsigned char *str);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned char	*ucbig;
	unsigned char	*uclittle;
	size_t			i;
	size_t			j;
	size_t			lenl;

	i = 0;
	j = 0;
	ucbig = (unsigned char *)big;
	uclittle = (unsigned char *)little;
	lenl = lenfc(uclittle);
	if (uclittle[0] == '\0')
		return ((char *)ucbig);
	while (ucbig[j] && len >= j + lenl)
	{
		while (uclittle[i] == ucbig[i + j] && ucbig[j + i] && uclittle[i])
			i++;
		if (uclittle[i] == '\0')
			return ((char *)&ucbig[j]);
		i = 0;
		j++;
	}
	return (NULL);
}

size_t	lenfc(unsigned char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
