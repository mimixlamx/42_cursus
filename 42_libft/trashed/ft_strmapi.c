/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:37:47 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 15:29:21 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
#include <stdlib.h>
/*
** need stdlib for malloc
*/

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
/*
char	fon(unsigned int i, char c)
{
	return (c + i);
}

int	main (void)
{
	char *rtn;

	rtn = ft_strmapi("test", fon);
	printf ("rtn = %s\n", rtn);
	free(rtn);
	rtn = NULL;
	return (0);
}*/
