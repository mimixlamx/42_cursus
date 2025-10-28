/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:41:11 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 10:39:27 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);
int		lenfonc(const char *str);
int		rtni(char const *s1, char const *set);
int		rtnj(char const *s1, char const *set);
char	*emptystr(void);

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

int	rtni(char const *s1, char const *set)
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

int	rtnj(char const *s1, char const *set)
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

int	lenfonc(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*emptystr(void)
{
	char	*rtn;

	rtn = malloc (1 * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	rtn[0] = '\0';
	return (rtn);
}
/*
int	main(void)
{
	char	*s1 = "-+-+-+test1234/+-+-+-";
	char	*set = "-4+";
	char	*rtn;

	rtn = ft_strtrim(s1, set);
	printf ("rtn = %s\n", rtn);
	free (rtn);
	rtn = NULL;
	return (0);
}
*/
/*
char	*ft_strtrim(char const *s1, char const *set);
int		len(const char *str);
char	*rtntmp(const char *s1);
char	*erasetemp(char *temp, int i);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	int		i;
	int		i2;

	temp = rtntmp(s1);
	while (set[i])
	{
		while (temp[i2])
		{
			if (temp[i2] == set[i])
			{
				temp = erasetemp(temp, i2);
				i2 = 0;
			}
			else
			i2++;
		}
		i2 = 0;
		i++;
	}
	return (temp);
}

char	*erasetemp(char *temp, int i)
{
	while (temp[i])
	{
		temp[i] = temp[i + 1];
		i++;
	}
	return (temp);
}

char	*rtntmp(const char *s1)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc (len(s1)* sizeof(char));
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	return (temp);
}
int	len(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*//*
int	main(void)
{
	char	*s1 = "  \t \t \n   \n\n\n\t";
	char	*set =" \t\n";
	char *rtn;

	rtn = ft_strtrim(s1, set);
	printf("rtn = %s\n", rtn);
}
*/
