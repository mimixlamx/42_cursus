#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
void	ft_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort(char *s, int start)
{
	int	i = start;
	int	j;

	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] > s[j])
				ft_swap(&s[i], &s[j]);
			j++;
		}
		i++;
	}
}
void	permute(char *s, int pos)
{
	int	i = pos;
	if (s[pos] == '\0')
	{
		write(1, s, ft_strlen(s));
		write(1, "\n", 1);
		return ;
	}
	while (s[i] != '\0')
	{
		ft_swap(&s[pos], &s[i]);
		sort(s, pos + 1);
		permute(s, pos + 1);
		sort(s, pos);
		i++;
	}
}
int	main(int ac, char **av)
{
	if (ac != 2 || !av[1][0])
		return (1);
	sort(av[1], 0);
	permute(av[1], 0);
	return (0);
}
