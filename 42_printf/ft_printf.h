/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:39:21 by mbruyere          #+#    #+#             */
/*   Updated: 2025/11/03 17:22:37 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
** double define protection
*/
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *str, ...);
int	ft_putnbr_base(int n, char *base, int i);
int	ft_putnbr(int n, int i);
int	ft_putunsigned(int n, int i);
int	ft_putchar(char c);
int	ft_putstr(char *str);
/*
** end
*/
#endif
