/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putvoidptr.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/13 11:32:13 by mbruyere       #+#    #+#                */
/*   Updated: 2025/11/18 14:44:45 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putvoidptr(void *ptr, int i)
{
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i = ft_putnbr_base((unsigned long)ptr, "0123456789abcdef", 0);
	return (i + 2);
}
/*
int	main(void)
{
	int i = 42;
	void *test = &i;

	ft_putvoidptr(test, i);
}*/
