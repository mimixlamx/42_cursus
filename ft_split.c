/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:41:10 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/14 09:44:19 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
#include <stdlib.h>

char	**ft_split(char const *s, char c);
int		lenword(int start, int end);
char	*string(const char *s, int start, int end);
int		countc(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		start;
	int		end;
	int		t;

	start = 0;
	t = 0;
	end = 0;
	array = malloc (countc(s, c) * sizeof(char *));
	while (s[end])
	{
		end++;
		while (s[end] != c && s[end])
			end++;
		array[t] = string(s, start, end);
		start = end + 1;
		t++;
	}
	return (array);
}

char	*string(const char *s, int start, int end)
{
	int		i;
	int		len;
	char	*rtn;

	len = lenword(start, end);
	i = 0;
	rtn = malloc(len + 1 * sizeof(char));
	while (i < len)
	{
		rtn[i] = s[start + i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int	lenword(int start, int end)
{
	int	i;

	i = 0;
	while (start + i < end)
		i++;
	return (i);
}

int	countc(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		s++;
		while (*s != c && *s)
			s++;
		count++;
	}
	return (count);
}
/*
int	main(void)
{
	char *s = "I/LOVE/BIG/BLACK";
	char c = '/';
	char **rtn;
	int count;
	int	count2;

	count2 = 0;
	count = countc(s, c);
	rtn = ft_split(s, c);
	while (count > count2)
	{
		printf ("rtn[%d] = %s\n", count2, rtn[count2]);
		count2++;
	}
	free (rtn);
	rtn = NULL;
}*/
