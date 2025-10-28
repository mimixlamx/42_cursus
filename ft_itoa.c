/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:36:37 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 14:14:43 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
** need stdlib for the malloc
*/
//#include <stdio.h>

static	int	lenn(long int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static	char	*final(char *rtn, long int n, int i, int j)
{
	char	tmp;

	while (n >= 10)
	{
		rtn[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	rtn[i] = n + '0';
	i++;
	rtn[i] = '\0';
	i--;
	while (i > j)
	{
		tmp = rtn[i];
		rtn[i] = rtn[j];
		rtn[j] = tmp;
		i--;
		j++;
	}
	return (rtn);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*rtn;
	int			i;
	int			j;
	long int	ln;

	ln = n;
	i = 0;
	j = 0;
	len = lenn(ln);
	rtn = malloc (len + 1 * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	if (ln < 0)
	{
		rtn[i] = '-';
		ln = ln * -1;
		i++;
		j++;
	}
	rtn = final(rtn, ln, i, j);
	return (rtn);
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
}
*/
//int		completion(int n);
//int		divalue(int n);
/*
char	*ft_itoa(int n)
{
	char	*rtn;
	int		i;

	rtn = lenn(n);
	i = 0;
	if (n < 0)
	{
		rtn[i] = '-';
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		rtn[i] = completion(n) + '0';
		i++;
		n = n % divalue(n);
	}
	rtn[i] = n + '0';
	i++;
	rtn[i] = '\0';
	return (rtn);
}
*
int	divalue(int n)
{
	int	div;

	div = 1;
	while (n >= 10)
	{
		div = div * 10;
		n = n / 10;
	}
	return (div);
}

int	completion(int n)
{
	while (n >= 10)
	{
		n = n / 10;
	}
	return (n);
}
*/
