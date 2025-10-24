/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:53:46 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/24 18:20:34 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	lenstr(char const *s);

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

size_t	lenstr(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char *str = "hola";
	char *rtn;

	rtn = ft_substr(str, 40, 0);
	printf ("rtn = %s\n", rtn);
	free (rtn);
	rtn = NULL;
	return (0);
}*/
