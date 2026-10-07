/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                          :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:41:10 by mbruyere          #+#    #+#             */
/*   Updated: 2026/04/30 16:03:05 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*string(const char *s, int start, int end)
{
	int		i;
	int		len;
	char	*rtn;

	len = 0;
	while (start + len < end)
		len++;
	i = 0;
	rtn = malloc((len + 1) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	while (i < len)
	{
		rtn[i] = s[start + i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

static	int	countc(const char *s, char c)
{
	int	count;
	int	i;
	int	y;
	/*
	int	in_simple;
	int	in_double;

	in_simple = 0;
	in_double = 0;
*/
	i = 0;
	y = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{	
		while (s[i] != c && s[i])
			i++;
		if (s[i] == c )
			count++;
		while (s[i] == c)
		{
			i++;
			y++;
		}
		if (s[i] == '\0')
		{
			if (y > 0)
				count--;
			return (count);
		}
		y = 0;
	}
	return (count);
}

static	char	**rtnarray(char const *s, char c, int e, int st)
{
	char	**array;
	int		t;

	t = 0;
	array = malloc ((countc(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (s[st] == c)
		st++;
	e = st;
	while (s[e])
	{
		while (s[e] != c && s[e])
			e++;
		if ((st == 0 && st != c) || ((s[e] == c || s[e] == '\0') && s[st] != c))
		{
			array[t] = string(s, st, e);
			while (s[e] == c)
				e++;
			st = e;
			t++;
		}
	}
	array[t] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		start;
	int		end;

	start = 0;
	end = 0;
	if (c == '\0')
	{
		if (s[0] == '\0')
		{
			array = malloc(1 * sizeof(char *));
			if (array == NULL)
				return (NULL);
			array[0] = NULL;
			return (array);
		}
		array = malloc (2 * sizeof(char *));
		if (array == NULL)
			return (NULL);
		array[0] = ft_strdup(s);
		array[1] = NULL;
		return (array);
	}
	array = rtnarray(s, c, end, start);
	return (array);
}
