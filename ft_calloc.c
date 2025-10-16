/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:49:02 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/16 12:03:11 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_calloc(size_t nmemb, size_t size)
{
	int					*array;
	long unsigned int	cnt;

	if (nmemb == 0 || size == 0)
		return ((void *)malloc(1 * sizeof(int)));
	cnt = 0;
	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	while (nmemb > cnt)
	{
		array[cnt] = 0;
		cnt++;
	}
	return ((void *)array);
}
/*
int main(void)
{
	int size = 0;
	int *rtnarray;
	int i = 0;

	rtnarray = callocc(size, sizeof(int));
	printf("result =");
	while (size > i)
	{
		printf(" %d", rtnarray[i]);
		i++;
	}
	free(rtnarray);
	rtnarray = NULL;
	return (0);
}
*/
