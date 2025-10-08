
#include <stdio.h>

#include <stdlib.h>
char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *rtn;
	int len;
	int len2;
	
	len = 0;
	len2 =0;
	while(s1[len])
		len++;
	while(s2[len2])
		len2++;
	rtn = malloc((len + len2 + 1) * sizeof(char));
	len = 0;
	while (s1[len])
	{
		rtn[len] = s1[len];
		len++;
	}
	len2 = 0;
	while (s2[len2])
	{
		rtn[len + len2] = s2[len2];
		len2++;
	}
	rtn[len +len2] = '\0';
	return (rtn);
}
