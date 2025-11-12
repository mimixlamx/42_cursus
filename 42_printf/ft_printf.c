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
** need ft_printf for all my functions
*/
static	int	half_check(const char *str, va_list args, int i);

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
			cnt += ft_putnbr(va_arg(args, int), 0);
		else if (str[i] == '%' && str[i + 1] == 'u')
			cnt += ft_putunsigned(va_arg(args, unsigned int), 0);
		else
			cnt += half_check(str, args, i);
		if (str[i] == '%')
			i += 2;
		else
			i++;
	}
	va_end(args);
	return (cnt);
}

static	int	half_check(const char *str, va_list args, int i)
{
	char	*base_maj;
	char	*base_min;
	int		cnt;

	base_maj = "0123456789ABCDEF";
	base_min = "0123456789abcdef";
	cnt = 0;
	if (str[i] == '%' && str[i + 1] == '%')
		cnt += ft_putchar('%');
	else if (str[i] == '%' && str[i + 1] == 'x')
		cnt += ft_putnbr_base(va_arg(args, unsigned int), base_min, 0);
	else if (str[i] == '%' && str[i + 1] == 'X')
		cnt += ft_putnbr_base(va_arg(args, unsigned int), base_maj, 0);
	else if (str[i] == '%' && str[i + 1] == 'p')
		cnt += ft_putvoidptr(va_arg(args, void *), 0);
	else if (str[i] && str[i] != '%')
		cnt += write (1, &str[i], 1);
	else if (str[i] == '%' && str[i + 1] == 'c')
		cnt += ft_putchar(va_arg(args, int));
	else if (str[i] == '%' && str[i + 1] == 's')
		cnt += ft_putstr(va_arg(args, char *));
	return (cnt);
}

/*
int	main(void)
{
	ft_printf("nbr = %d", ft_printf(" %p %p ", 0, 0));
}
*/
/*
int	main(void)
{
	ft_printf("test = %d\n", ft_printf(" %x ", -1));
}
*/
/*
int	main(void)
{
	int	i = ft_printf("test%s", "");
	ft_printf("count = %d\n", i);
}
*/
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
	void			ptr;

	str = "c'est déja bien hein";
	d = 15;
	c = 's';
	i = 10;
	u = 4294967295;
	x = 346;
	X = 346;
	ft_printf("%d", ft_printf("%d%c %s%%%i%u%x%X%p", d, c, str, i, u, x, X, ptr));
}*/
