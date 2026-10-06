#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (0);
}
char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	char *rtn;

	i = 0;
	rtn = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (rtn == NULL)
		return (NULL);
	while(s1 && s1[i])
	{
		rtn[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		rtn[i + j] = s2[j];
		j++;
	}
	rtn[i + j] = '\0';
	free(s1);
	return(rtn);
}

char *get_next_line(int fd)
{
	static char *stash = NULL;
	char *line;
	char *tmp;
	int	i;
	int	r;
	char buf[BUFFER_SIZE + 1];
	
	i = 0;
	r = 1;
	while (ft_strchr(stash, '\n') == 0  && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r > 0)
		{
			buf[r] = '\0';
			stash = ft_strjoin(stash, buf);
		}
	}
	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	while(stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + (stash[i] == '\n') + 1);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	tmp = ft_strjoin(NULL, stash + i);
	free(stash);
	if (tmp && tmp[0] == '\0')
	{
		free(tmp);
		stash = NULL;
	}
	else
		stash = tmp;
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;
	char *line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
