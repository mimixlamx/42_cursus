/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:30:24 by mbruyere          #+#    #+#             */
/*   Updated: 2025/09/30 15:34:07 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
/*
#include <stdio.h>
*/
void	*memset(void *s, int c, size_t n);

void	*memset(void *s, int c, size_t n)
{
	unsigned char	*b;

	b = s;
	while (n > 0)
	{
		*b = c;
		n--;
		b++;
	}
	return (s);
}
/*
int	main(void)
{
	char buffer[10];
	memset(buffer, 'a', 5);
	printf("string = %s", buffer);
	return (0);
}*/
