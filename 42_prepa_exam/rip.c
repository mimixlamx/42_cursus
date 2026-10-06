#include <stdio.h>
#include <unistd.h>

static void	solve(char *s, int i, int op, int cl)
{
	int	j;
	int	k;
	int	n;

	if (op == 0 && cl == 0)
	{
		k = 0;
		n = 0;
		while (s[n])
		{
			if (s[n] == '(') k++;
			else if (s[n] == ')') {if (k-- == 0) return ;}
			n++;
		}
		if (k == 0)
			puts(s);
		return ;
	}
	j = i;
	while (s[j])
	{
		if (j > i && s[j] == s[j - 1])
		{
			j++;
			continue ;
		}
		if (s[j] == ')' && cl > 0)
		{
			s[j] = ' ';
			solve(s, j + 1, op, cl - 1);
			s[j] = ')';
		}
		if (s[j] == '(' && op > 0)
		{
			s[j] = ' ';
			solve(s, j + 1, op - 1, cl);
			s[j] = '(';
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	op;
	int	cl;
	int	i;

	if (argc != 2)
		return (1);
	op = 0;
	cl = 0;
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '(')
			op++;
		else if (argv[1][i] == ')' && op > 0)
			op--;
		else if (argv[1][i] == ')')
			cl++;
		i++;
	}
	solve(argv[1], 0, op, cl);
	return (0);
}
