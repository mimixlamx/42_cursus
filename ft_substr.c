/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:53:46 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/09 10:53:49 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	lenstr(char const *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;

	if (start >= lenstr(s))
		len = 0;
	if (len > lenstr(s))
		len = lenstr(s);
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
	char *str = "holla";
	char *rtn;

	rtn = ft_substr(str, 2, 1);
	printf ("rtn = %s\n", rtn);
	free (rtn);
	rtn = NULL;
	return (0);
}
*/
