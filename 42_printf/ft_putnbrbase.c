/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:38:30 by mbruyere          #+#    #+#             */
/*   Updated: 2025/11/03 17:42:22 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	ft_lenbase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr_base(unsigned long nbr, char *base, int i)
{
	unsigned int			lenbase;

	lenbase = ft_lenbase(base);
	if (nbr <= lenbase - 1)
	{
		write(1, &base[nbr], 1);
		i++;
	}
	else if (nbr >= lenbase)
	{
		i += ft_putnbr_base(nbr / lenbase, base, 0);
		i += ft_putnbr_base(nbr % lenbase, base, 0);
	}
	return (i);
}
/*
int	main(void)
{
	printf("%d", ft_putnbr_base(-346, "0123456789abcdef", 0));
}*/
