/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_atol.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/12 17:27:39 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/12 17:36:38 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *nptr)
{
	long	rtn;
	long	signe;

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
