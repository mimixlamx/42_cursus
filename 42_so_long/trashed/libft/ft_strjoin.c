/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:45:16 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 16:54:27 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
** need stdlib for malloc
*/
static	char	*phase(char const *s1, char const *s2)
{
	char	*rtn;
	int		len;
	int		len2;

	len = 0;
	len2 = 0;
	while (s1[len])
		len++;
	while (s2[len2])
		len2++;
	rtn = malloc((len + len2 + 1) * sizeof(char));
	return (rtn);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	int		len;
	int		len2;

	rtn = phase(s1, s2);
	if (rtn == NULL)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		rtn[len] = s1[len];
		len++;
	}
	len2 = 0;
	while (s2[len2])
	{
		rtn[len + len2] = s2[len2];
		len2++;
	}
	rtn[len + len2] = '\0';
	return (rtn);
}
