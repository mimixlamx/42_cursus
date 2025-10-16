/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:36:37 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/16 15:03:48 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int n);
int		lenn(int n);

char	*ft_itoa(int n)
{
	char	*rtn;
	int		i;
	int		temp;
	int		len;

	len = lenn(n);
	rtn = malloc ((len + 1) * sizeof(char));
	i = 0;
	if (n < 0)
	{
		rtn[i] = '-';
		n = n * -1;
		i++;
	}
	// ajouter ecriture par la fin sans reverse recursive /10 %10 tah le putnbr ?
	while (n != 0)
	{
		temp = n % 10;
		temp = temp + '0';
		rtn[i] = temp;
		n = n / 10;
		i++;
		if (n == 0)
			rtn[i] = '\0';
	}
	return (rtn);
}

int	lenn(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n / 10 > 0)
	{
		n = n % 10;
		i++;
	}
	i++;
	return (i);
}

int	reverse(int n)
{
	int	reversed;

	reversed = 0;
	while (n / 10 > 0)
	{
		reversed = (reversed * 10) + (n % 10);
		n = n / 10;
	}
	reversed = (reversed * 10) + (n % 10);
	return (reversed);
}

int	main(void)
{
	int		n;
	char	*rtnvalue;

	n = 112345670;
	rtnvalue = ft_itoa(n);
	printf ("rtnvalue = %s\n", rtnvalue);
	free (rtnvalue);
	rtnvalue = NULL;
	return (0);
}
