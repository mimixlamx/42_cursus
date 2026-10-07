/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:58:37 by mbruyere          #+#    #+#             */
/*   Updated: 2026/03/12 17:27:30 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	rtn;
	int	signe;

	signe = 1;
	rtn = 0;
	while (*nptr == 32 || (*nptr <= 13 && *nptr >= 9))
		nptr++;
	if (*nptr == '-')
	{
		signe = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		rtn = rtn * 10 + (*nptr - '0');
		nptr++;
	}
	rtn = rtn * signe;
	return (rtn);
}
