/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:54:33 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 13:38:20 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
#include <stdio.h>
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*
int	main(void)
{
	int	tkt;

	tkt = 'Z';
	write (1, &tkt, 1);
	printf ("tkt before = %d\n", tkt);
	tkt = tolowerr(tkt);
	write (1, &tkt,1);
	printf ("tkt after = %d\n", tkt);
	return (0);
}
*/
