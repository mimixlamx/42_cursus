#include <stdio.h>
#include <stdlib.h> 

void	print_set(int *tab, int size, int mask)
{
	int	i;
	int first;

	i = 0;
	first = 0;
	while (i < size)
	{
		if (mask & (1 << i))
		{
			if (!first)
				printf(" ");
			printf("%d", tab[i]);
			first = 0;
		}
		i++;
	}
	printf("\n");
}
int	main(int ac, char **av)
{
	int target;
	int tab[30];
	int size;
	int mask;
	int limit;
	int i;
	int sum;

	if(ac < 3)
		return (1);
	target = atoi(av[1]);
	size = ac - 2;
	i = 0;
	while (i < size)
	{
		tab[i] = atoi(av[i + 2]);
		i++;
	}
	limit = 1 << size;
	mask = 0;
	while (mask < limit)
	{
		i = 0;
		sum = 0;
		while(i < size)
		{
			if (mask & (1 << i))
				sum = sum + tab[i];
			i++;
		}
		if (sum == target)
			print_set(tab, size, mask);
		mask++;
	}
	return (0);
}