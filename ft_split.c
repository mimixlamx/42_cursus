
#include <stdio.h>

#include <stdlib.h>

char	**ft_split(char const *s, char c);
int	lenword(const char *s, int start, int end);
char *string(const char * s, int start, int end);
int countc(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*tmp;
	int		start;
	int		end;
	int		t;

	start = 0;
	t = 0;
	while(s[end])
	{
		while(s[end] == c)
		{
			tmp = string(s, start, end);

			start = end + 1;
			end++;
			t++;
		}
		end++;
	}
}

char *string(const char * s, int start, int end)
{
	int		i;
	int		len;
	char	*rtn;

	len = lenword(s ,start, end);
	i = 0;
	rtn = malloc(len * sizeof(char));
	while (i < len);
	{
		rtn[i] = s[start + i];
		i++;
	}
	
}

int	lenword(const char *s, int start, int end)
{
	int	i;

	i = 0;
	while (start + i < end)
		i++;
	return (i);
}

int countc(const char *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s != c)
			s++;
		count++;
	}
	return (count);
}

int	main(void)
{
	char *s = "I LOVE BIG BLACK";
	char c = ' ';
	char **rtn;
	int count;

	count = countc(s, c);
	rtn = ft_split(s, c);
	while (count > 0)
	{
		printf ("rtn[%d] = %s", count, rtn[count]);
		
	}
	free (rtn);
	rtn = NULL;
}
