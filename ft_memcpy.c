#include <stddef.h>
/*
#include <stdio.h>
*/
void	*memcpy(void *dest, const void *src, size_t n);

void	*memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
}
/*
int	main(void)
{
	char src[10] = "123456789";
	char dest[10] = "ABCDEFGHI";
	memcpy(dest, src, 5);
	printf("string dest = %s", dest);
	return (0);
}*/
