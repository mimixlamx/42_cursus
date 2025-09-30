/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:13:12 by mbruyere          #+#    #+#             */
/*   Updated: 2025/09/30 17:14:05 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
#include <stdio.h>
*/
void	bzero(void *s, size_t n);

void	bzero(void *s, size_t n)
{
	unsigned char	*b;

	b = s;
	while (n > 0)
	{
		*b = '\0';
		n--;
		b++;
	}
}
/*
int	main(void)
{
	char buffer[10] = "tkt123456";
	printf("string1 = %s\n", buffer);
	bzeroo(buffer, 5);
	printf("string = %s", buffer);
		return (0);
}*/
