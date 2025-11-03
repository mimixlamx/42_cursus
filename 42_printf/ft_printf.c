/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyere <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:38:12 by mbruyere          #+#    #+#             */
/*   Updated: 2025/11/03 17:56:33 by mbruyere         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

/*
** need stdarg for va_list...
** need unistd for write
*/

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		cnt;

	cnt = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 'd' || str[i +1] == 'i'))
		{
			cnt += ft_putnbr(va_arg(args, int), 0);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 'u')
		{
			cnt += ft_putunsigned(va_arg(args, unsigned int), 0);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 'c')
		{
			cnt += ft_putchar(va_arg(args, int));
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			cnt += ft_putstr(va_arg(args, char *)) - 1;
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			cnt += ft_putchar('%');
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 'x')
		{
			cnt += ft_putnbr_base(va_arg(args, int), "0123456789abcdef", 0);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 'X')
		{
			cnt += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 0);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 'p')
		{
			cnt += ft_putptr(va_arg(args, void *), 0);
			i += 2;
		}
		else if (str[i] && str[i] != '%')
		{
			write (1, &str[i], 1);
			i++;
			cnt++;
		}
	}
	va_end(args);
	return (cnt);
}
/*
int	main(void)
{
	int				d;
	char			c;
	char			*str;
	int				i;
	unsigned int	u;
	int				x;
	int				X;

	str = "c'est déja bien hein";
	d = 15;
	c = 's';
	i = 10;
	u = 4294967295;
	x = 346;
	X = 346;
	ft_printf("%d", ft_printf("%d%c %s%%%i%u%x%X", d, c, str, i, u, x, X));
}*/
