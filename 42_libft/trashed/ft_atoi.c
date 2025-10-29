/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:58:37 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 14:10:53 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>

#include <stddef.h>
*/
int	ft_atoi(const char *nptr)
{
	int	rtn;
	int	signe;

	rtn = 0;
	while (*nptr == 32 || (*nptr <= 13 && *nptr >= 9))
		nptr++;
	if (*nptr == '-')
	{
		signe = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		signe = 1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		rtn = rtn * 10 + (*nptr - 48);
		nptr++;
	}
	if (signe < 0)
		rtn = rtn * signe;
	return (rtn);
}
/*
int	main(void)
{
	char	*tkt;
	int		rtn;

	tkt = "945";
	rtn = ft_atoi(tkt);
	printf("rtn = %d \n", rtn);
	return (0);
}
*/
