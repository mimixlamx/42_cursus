/*
#include <unistd.h>
#include <stdio.h>
*/
int	toupper(int c);

int toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
int	main(void)
{
	int	tkt;

	tkt = '/';
	write (1, &tkt, 1);
	printf ("tkt before = %d\n", tkt);
	tkt = toupperr(tkt);
	write (1, &tkt,1);
	printf ("tkt after = %d\n", tkt);
	return (0);
}*/
