/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:39:21 by mbruyere          #+#    #+#             */
/*   Updated: 2025/11/20 12:47:00 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
/*
** double define protection
*/
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
/*
** need unistd and stdarg in some codes
*/
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
