/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:28:29 by mbruyere          #+#    #+#             */
/*   Updated: 2025/11/20 12:42:06 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
/*
** need ft_printf for all my functions and includes
*/

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}
