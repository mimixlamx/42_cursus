/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:41:10 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/24 19:15:10 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	**ft_split(char const *s, char c);
void	freememory(char **array, int t);
char	*string(const char *s, int start, int end);
int		countc(const char *s, char c);
char	**rtnarray(char const *s, char c, int end, int start);

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		start;
	int		end;

	start = 0;
	end = start;
	if (c == '\0')
	{
		if (s[0] == '\0')
		{
			array = malloc (1 * sizeof(char *));
			if (array == NULL)
				return (NULL);
			array[0] = NULL;
			return (array);
		}
		array = malloc (2 * sizeof(char *));
		if (array == NULL)
			return (freememory(array, 1), NULL);
		array[0] = ft_strdup(s);
		array[1] = NULL;
		return (array);
	}
	array = rtnarray(s, c, end, start);
	return (array);
}

char	**rtnarray(char const *s, char c, int e, int st)
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

char	*string(const char *s, int start, int end)
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

void	freememory(char **array, int t)
{
	while (t >= 0)
	{
		free(array[t]);
		t--;
	}
}

int	countc(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (count);
		count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}
/*
int	main(void)
{
	char *s = "\0non\0empty";
	char c = '\0';
	char **rtn;
	int count;
	int	count2;

	count2 = 0;
	count = 2;
	rtn = ft_split(s, c);
	while (count > count2)
	{
		printf ("rtn[%d] = %s\n", count2, rtn[count2]);
		count2++;
	}
	free (rtn);
	rtn = NULL;
}*/
