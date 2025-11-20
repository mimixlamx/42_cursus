/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:08:48 by mbruyere          #+#    #+#             */
/*   Updated: 2025/11/20 12:42:34 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
/*
** need ft_printf for all my functions and includes
*/

int	ft_putnbr(int n, int i)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr = nbr * -1;
		i++;
	}
	if (nbr >= 0 && nbr <= 9)
	{
		nbr += '0';
		write (1, &nbr, 1);
		i++;
	}
	else
	{
		i = i + ft_putnbr(nbr / 10, 0);
		i = i + ft_putnbr(nbr % 10, 0);
	}
	return (i);
}
