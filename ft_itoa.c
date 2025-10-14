/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:36:37 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/14 09:37:09 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <stdio.h>
*/
char	*ft_itoa(int n);
int		lenn(int n);
int		reverse(int n);

char	*ft_itoa(int n)
{
	char	*rtn;
	int		i;
	int		temp;

	rtn = malloc ((lenn(n) + 1) * sizeof(char));
	i = 0;
	if (n < 0)
	{
		rtn[i] = '-';
		n = n * -1;
		i++;
	}
	n = reverse (n);
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
/*
int	main(void)
{
	int		n;
	char	*rtnvalue;

	n = 0;
	rtnvalue = ft_itoa(n);
	printf ("rtnvalue = %s\n", rtnvalue);
	free (rtnvalue);
	rtnvalue = NULL;
	return (0);
}*/
