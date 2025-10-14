/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:38:37 by mbruyere          #+#    #+#             */
/*   Updated: 2025/10/14 09:39:47 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
#include <stdio.h>
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	f(unsigned int i, char *tkt)
{
	if (i %2 == 0)
		*tkt = *tkt - 32;
	else 
		*tkt = *tkt - 32;
}

int	main(void)
{
	char	ptr[] = "test";
	ft_striteri(ptr, f);
	printf ("ptr = %s\n", ptr);
	return (0);

}*/
