#include <unistd.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		len;
	char	buf[10000];
	char	c;
	
	i = 0;
	if (ac != 2)
		return (1);
	len = strlen(av[1]);
	while (read(0, &c, 1) > 0)
	{
		buf[i] = c;
		i++;
		if (i == len)
		{
			if (!ft_strncmp(buf, av[1], len))
			{
				while (i >  0)
				{
					write(1, "*", 1);
					i--;
				}
			}
			else
			{
				write(1, &buf[0], 1);
				memmove(buf, buf + 1, len - 1);
				i--;
			}
		}
	}
	if (i)
		write(1, buf, i);
	return(0);
}
