/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:35:49 by mbruyere          #+#    #+#             */
/*   Updated: 2025/09/30 13:36:58 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
*/
int	isascii(int c);

int	isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (c);
	return (0);
}
/*
int	main(void)
{
	int	c;
	int	tkt;

	c = 128;
	tkt = isascii(c);
	write (1, &tkt, 1);
}
*/
