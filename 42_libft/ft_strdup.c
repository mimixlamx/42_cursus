/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:51:43 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 16:54:00 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

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
