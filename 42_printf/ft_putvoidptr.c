#include <unistd.h>
#include "ft_printf.h"

int	ft_putvoidptr(void *ptr, int i)
{
	if (ptr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	i = ft_putnbr_base((unsigned long)ptr, "0123456789abcdef", 0);
	return (i + 2);
}
/*
int	main(void)
{
	int i = 42;
	void *test = &i;

	ft_putvoidptr(test, i);
}*/
