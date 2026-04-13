/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:00:46 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 16:55:50 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
/*
** need stddef for size_t
*/
static	size_t	lenfc(unsigned char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
