/*
#include <stdio.h>
*/
#include <stddef.h>
void *memchr(const void *s, int c, size_t n);

void *memchr(const void *s, int c, size_t n)
{
	const unsigned char *tkt;
	tkt = s;
	while (n > 0 && *tkt != c)
	{
		n--;
		tkt++;
	}
	if (*tkt == c)
		return (void*)tkt;
	return (NULL);
}
/*
int	main(void)
{
	char s[10] = "test123c";
	int c = 'c';
	int n = 10;
	unsigned char *rtn = memchrr(s, c, n);
	printf ("rtn = %s \n", rtn);
	return(0);
}*/
