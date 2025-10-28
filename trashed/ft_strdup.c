/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:51:43 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 14:48:46 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
#include <stdlib.h>
/*
** need stdlib for null and malloc
*/
char	*ft_strdup(const char *s)
{
	int		len;
	char	*rtn;

	len = 0;
	while (s[len])
		len++;
	len++;
	rtn = malloc(len * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	len = 0;
	while (s[len])
	{
		rtn[len] = s[len];
		len++;
	}
	rtn[len] = '\0';
	return ((char *)rtn);
}
/*
int main(void)
{
	char *original = "test1234/";
	char *cpy;

	cpy = strdupp(original);
	printf ("original = %s\ncpy = %s\n", original, cpy);
	free (cpy);
	cpy = NULL;
	return (0);
}
*/
