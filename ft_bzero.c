/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:13:12 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 16:48:42 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
 ** need stddef for the size_t
*/

void	ft_bzero(void *s, size_t n)
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
