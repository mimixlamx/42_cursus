/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:41:37 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/14 14:46:54 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_isprint(int c);

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
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
