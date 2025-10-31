#include <stdarg.h>
#include <unistd.h>
/*
** need stdarg for va_list...
*/

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write (fd, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= 0 && nbr <= 9)
	{
		nbr = nbr + '0';
		write(fd, &nbr, 1);
	}
	else if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int i;

	i = 0;
	va_start(args,  str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'd')
		{
			ft_putnbr_fd(va_arg(args, int), 1);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 'c')
		{
			ft_putchar(va_arg(args, int));
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			ft_putstr_fd(va_arg(args, char *), 1);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar('%');
			i += 2;
		}
		else if (str[i] && str[i] != '%')
		{
			write (1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	int		d;
	char	c;
	char	*str;

	str = "c'est déja bien hein";
	d = 15;
	c = 's';
	ft_printf("%d%c %s%%", d, c, str);
}
