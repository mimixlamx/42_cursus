/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:55:27 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/14 11:57:03 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
#include <stdio.h>
*/
int	ft_toupper(int c);

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
int	main(void)
{
	int	tkt;

	tkt = '/';
	write (1, &tkt, 1);
	printf ("tkt before = %d\n", tkt);
	tkt = toupperr(tkt);
	write (1, &tkt,1);
	printf ("tkt after = %d\n", tkt);
	return (0);
}*/
