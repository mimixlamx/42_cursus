#include "philo.h"

/*
 ** long pour gerer le cas trop grand
 ** on accepte les plus mais pas un null ou autre chose que 0-9
 ** *10 poujr decaler et on ajoute le nouveau
 ** retour en intg avant de quit
*/

static int	to_int(const char *s, int *out)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	if (s[i] == '+')
		i++;
	if (!s[i])
		return (1);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		n = n * 10 + (s[i] - '0');
		if (n > 2147483647)
			return (1);
		i++;
	}
	*out = (int)n;
	return (0);
}

/*
 ** 5 ou 6 argument
 ** transformer lesargv en int et stocker dans a
 ** -1 pas de 6eme argv
 ** si 6 eme on int le dernier 
 ** check valeurs a 0
*/

int	parse_args(int argc, char **argv, t_args *a)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (to_int(argv[1], &a->nb_philo) || to_int(argv[2], &a->t_die)
		|| to_int(argv[3], &a->t_eat) || to_int(argv[4], &a->t_sleep))
		return (1);
	a->must_eat = -1;
	if (argc == 6 && to_int(argv[5], &a->must_eat))
		return (1);
	if (a->nb_philo <= 0 || a->t_die <= 0 || a->t_eat <= 0
		|| a->t_sleep <= 0 || (argc == 6 && a->must_eat <= 0))
		return (1);
	return (0);
}
