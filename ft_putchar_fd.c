#include <unistd.h>

void	ft_putchar_fd(char c, int fd);

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
int	main(void)
{
	ft_putchar_fd('a', 2);
	write (2, "\n", 1);
	write (0, "test\n", 5);
	return(0);
}*/
