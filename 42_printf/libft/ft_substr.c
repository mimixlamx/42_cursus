/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:53:46 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 16:57:31 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
** need libft for ft_strdup
** need stdlib for NULL
*/

static	size_t	lenstr(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= lenstr(s))
		return (ft_strdup("\0"));
	if (len > lenstr(s + start))
		len = lenstr(s + start);
	i = 0;
	rtn = malloc (len + 1 * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	while (len > i && s[start + i])
	{
		rtn[i] = s[start + i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
