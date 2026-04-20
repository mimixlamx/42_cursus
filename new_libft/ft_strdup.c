/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:51:43 by mbruyere          #+#    #+#             */
/*   Updated: 2026/04/20 14:38:47 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
