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

/*
#include <stdio.h>
*/
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*rtn;
	long unsigned int	i;

	i = 0;
	rtn = malloc (len * sizeof(char));
	while (s[start + i] && i + 1 < len)
	{
		rtn[i] = s[start + i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
/*
int	main(void)
{
	char *str = "test1234/";
	char *rtn;

	rtn = ft_substr(str, 4, 4);
	printf ("rtn = %s\n", rtn);
	free (rtn);
	rtn = NULL;
	return (0);
}
*/
