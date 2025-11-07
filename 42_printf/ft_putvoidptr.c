#include <unistd.h>
#include "ft_printf.h"

int	ft_putvoidptr(void *ptr)
{
	write(1,"x0", 2);
	ft_putnbr_base(&(int)*ptr, "0123456789ABCDEF", 0);
	return (2);
}

int	main(void)
{
	void *test;

	ft_putvoidptr((void *)test);
}
