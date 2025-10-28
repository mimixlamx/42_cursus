/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:49:02 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 16:49:01 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
 ** need stdlib for the malloc
*/
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
