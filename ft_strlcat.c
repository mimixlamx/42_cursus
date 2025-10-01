/*
#include <stdio.h>
*/
#include <stddef.h>
size_t	strlcat(char *dst, const char *src, size_t size);

size_t	strlcat(char *dst, const char *src, size_t size)
{
	int tkt;

	tkt = 0;
	while (*dst)
	{
		tkt++;
		dst++;
		size--;
	}
	while(size > 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		tkt++;
		size--;
	}
	dst = '\0';
	return (tkt);
}
/*
int	main(void)
{
	char	dest[20] = "\0";
	char	*source = "hello";
	int		len;

	len = strlcat(dest, source, sizeof(dest));
	printf("len = %d \n", len);
	printf("concat = %s \n", dest);
	return(0);
}*/
