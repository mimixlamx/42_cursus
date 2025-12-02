/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:39:21 by mbruyere          #+#    #+#             */
/*   Updated: 2025/12/02 14:33:14 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
/*
** double define protection
*/
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr_base(unsigned long nbr, char *base, int i);
int	ft_putnbr(int n, int i);
int	ft_putunsigned(int n, int i);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putvoidptr(void *ptr, int i);
/*
** end
*/
#endif
