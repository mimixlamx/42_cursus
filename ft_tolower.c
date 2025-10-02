/*
#include <unistd.h>
#include <stdio.h>
*/
int	tolower(int c);

int tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*
int	main(void)
{
	int	tkt;

	tkt = 'Z';
	write (1, &tkt, 1);
	printf ("tkt before = %d\n", tkt);
	tkt = tolowerr(tkt);
	write (1, &tkt,1);
	printf ("tkt after = %d\n", tkt);
	return (0);
}
*/
