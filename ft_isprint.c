/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:41:37 by mbruyere          #+#    #+#             */
/*   Updated: 2025/09/30 13:43:02 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
*/
int	isprint(int c);

int	isprint(int c)
{
	if (c >= 33 && c <= 126)
		return (c);
	return (0);
}
/*
int	main(void)
{
	int	c;
	int	tkt;

	c = 30;
	tkt = isprint(c);
	write (1, &tkt, 1);
}
*/
