/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:58:37 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/03 11:24:57 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
#include <stddef.h>

int	atoi(const char *nptr);

int	atoii(const char *nptr)
{
	int	rtn;
	int	signe;

	signe = *nptr;
	rtn = 0;
	while (*nptr)
	{
		while (*nptr >= '0' && *nptr <= '9')
		{
			rtn = rtn * 10 + (*nptr - 48);
			nptr++;
		}
		nptr++;
	}
	if (signe == '-')
		rtn = rtn * -1;
	return (rtn);
}
/*
int	main(void)
{
	char	*tkt;
	int		rtn;

	tkt = "125f5";
	rtn = atoii(tkt);
	printf("rtn = %d \n", rtn);
	return (0);
}
*/
