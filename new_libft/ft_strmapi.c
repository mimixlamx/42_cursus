/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:37:47 by mbruyere          #+#    #+#             */
/*   Updated: 2026/04/20 14:40:55 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	lens(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*rtn;

	i = 0;
	rtn = malloc (lens(s) +1 * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	while (s[i])
	{
		rtn[i] = f(i, s[i]);
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
