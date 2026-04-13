/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:41:11 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 16:57:20 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
** need stdlib for malloc and NULL
*/

static	int	rtni(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		while (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

static	int	lenfonc(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	int	rtnj(char const *s1, char const *set)
{
	int	i;
	int	j;

	j = 0;
	i = lenfonc(s1) - 1;
	while (set[j])
	{
		while (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		j++;
	}
	return (i);
}

static	char	*emptystr(void)
{
	char	*rtn;

	rtn = malloc (1 * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	rtn[0] = '\0';
	return (rtn);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*rtn;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	start = rtni(s1, set);
	end = rtnj(s1, set);
	if (start > end)
		return (emptystr());
	len = end - start + 1;
	rtn = malloc((len + 1) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	while (len > i)
	{
		rtn[i] = s1[start + i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
