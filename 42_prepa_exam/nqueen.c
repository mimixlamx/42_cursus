#include <stdlib.h>
#include <stdio.h>

int	n;
int	*q;

void	solve(int col)
{
	if (col == n)
	{
		for(int i = 0; i < n; i++)
			fprintf(stdout, i? "%d" : "%d", q[i]);
		fprintf(stdout, "\n");
		return;
	}
	for(int row = 0; row < n; row++)
	{
		int	ok = 1;
		for(int c = 0; c < col; c++)
			if (q[c] == row || abs(q[c]-row) == col - c)
			{
				ok = 0;
				break;
			}
		if (ok)
		{
			q[col] = row;
			solve(col + 1);
		}
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	n = atoi(av[1]);
	q = malloc(n *sizeof(int));
	solve(0);
	free(q);
	return (0);
}