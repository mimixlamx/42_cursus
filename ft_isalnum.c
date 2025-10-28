/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:20:41 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 13:33:44 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
*/
int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (c);
	return (0);
}
/*
int	main(void)
{
	int	c;
	int	tkt;

	c = 'c';
	tkt = isalnum(c);
	write (1, &tkt, 1);
}*/
