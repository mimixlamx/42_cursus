/*
#include <stdio.h>
*/
#include <stdlib.h>
char	*strdup(const char *source);

char	*strdup(const char *source)
{
	int len;
	char *rtn;

	len = 0;
	while (source[len])
		len++;
	len++;
	rtn = malloc(len * sizeof(char));
	len = 0;
	while (source[len])
	{
		rtn[len] = source[len];
		len++;
	}
	rtn[len] = '\0';
	return ((char*)rtn);
}
/*
int main(void)
{
	char *original = "test1234/";
	char *cpy;

	cpy = strdupp(original);
	printf ("original = %s\ncpy = %s\n", original, cpy);
	free (cpy);
	cpy = NULL;
	return (0);
}
*/
