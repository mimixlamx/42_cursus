/*
#include <stdio.h>
*/
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int lens(char const *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*rtn;

	i = 0;
	rtn = malloc (lens(s) +1 * sizeof(char));
	while (s[i])
	{
		rtn[i] = f(i, s[i]);
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int lens(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
char	fon(unsigned int i, char c)
{
	return (c + i);
}

int	main (void)
{
	char *rtn;

	rtn = ft_strmapi("test", fon);
	printf ("rtn = %s\n", rtn);
	free(rtn);
	rtn = NULL;
	return (0);
}*/
