/*
#include <stdio.h>
*/
#include <stddef.h>
size_t	strlcpy(char *dst, const char *src, size_t size);

size_t	strlcpy(char *dst, const char *src, size_t size)
{
	int tkt;

	tkt = 0;
	while (size > 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
		tkt++;
	}
	while (*src)
	{
		src++;
		tkt++;
	}
	*dst = '\0';
	return (tkt);
}
/*
int	main(void)
{
	char dest[10];
	const char *source = "012345678910";
	int len;

	len = strlcpyy(dest, source, sizeof(dest));
	printf ("dest = %s \n", dest);
	printf ("len = %d \n", len);
	if (len >= sizeof(dest))
		printf ("moins de bytes que a l'origine");
	else
		printf ("meme nombres de bites");
	return (0);

}
*/
