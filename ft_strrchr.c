/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:50:07 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/14 11:56:31 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
#include <stddef.h>

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	int					len;
	unsigned char		ucc;
	unsigned char		*cucs;

	cucs = (unsigned char *)s;
	ucc = (unsigned char)c;
	len = 0;
	while (cucs[len])
		len++;
	while (cucs[len] != ucc && len > 0)
		len--;
	if (cucs[len] == ucc)
		return ((char *)&cucs[len]);
	return (NULL);
}
/*
int	main(void)
{
	const char *tkt = "amenegea";
	int a = 'a';
	char *rtn = strrchrr(tkt, a);
	printf("string = %s\n", rtn);
	return (0);
}
*/
