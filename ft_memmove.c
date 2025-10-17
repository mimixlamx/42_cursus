/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:00:48 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/17 18:32:09 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n);
void	reversemove(unsigned char *d, const unsigned char *s, size_t n);
void	move(unsigned char *d, const unsigned char *s, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0 || dest == src)
		return (dest);
	if (d < s)
		move(d, s, n);
	else
		reversemove(d, s, n);
	return (dest);
}

void	move(unsigned char *d, const unsigned char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}

}

void	reversemove(unsigned char *d, const unsigned char *s, size_t n)
{
	int i;

	i = n;
	while (i > 0 )
	{
		i--;
		d[i] = s[i];
	}
}
/*
int	main(void)
{
	char src[10] = "123456789";
	char dest[10] = "ABCDEFGHI";
	memmovee(dest, src, 5);
	printf("string dest = %s", dest);
	return (0);
}*/
