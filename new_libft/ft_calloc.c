/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:49:02 by mbruyere          #+#    #+#             */
/*   Updated: 2026/04/20 14:31:43 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*array;
	size_t		cnt;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	cnt = 0;
	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	while ((nmemb * size) > cnt)
	{
		array[cnt] = 0;
		cnt++;
	}
	return (array);
}
