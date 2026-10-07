/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                    :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:51:43 by mbruyere          #+#    #+#             */
/*   Updated: 2025/12/02 14:34:18 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunsigned(int n, int i)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr <= 9)
	{
		nbr = nbr + '0';
		write(1, &nbr, 1);
		i++;
	}
	else if (nbr >= 10)
	{
		i += ft_putunsigned(nbr / 10, 0);
		i += ft_putunsigned(nbr % 10, 0);
	}
	return (i);
}
