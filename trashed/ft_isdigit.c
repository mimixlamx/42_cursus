/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:12:38 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/28 13:33:19 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}
/*
int main(void)
{
	int c;
	int tkt;

	c = 'a';
	tkt = isdigit(c);
	write (1, &tkt, 1);
}
*/
