#include "philo.h"

/*
 ** boucle sur le tableau et initialise les data 
 ** id + 1 car on commence a 1 pas 0
 ** meal a 0 evidement
 ** fourchett gauche = celle duphilo
 ** fourchette droite = celle du philo +1 le modulo sert a la fin de la table
 ** adrese de la table
*/

static void	init_philos(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->a.nb_philo)
	{
		t->philos[i].id = i + 1;
		t->philos[i].meals_count = 0;
		t->philos[i].last_meal = 0;
		t->philos[i].left = &t->forks[i];
		t->philos[i].right = &t->forks[(i + 1) % t->a.nb_philo];
		t->philos[i].table = t;
		i++;
	}
}

/*
 ** initialisation  des sécu
 ** pour chaque philo on mutex les fork et les meal mutex
 ** mais aussi print et stop dans la table 
*/

static int	init_mutexes(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->a.nb_philo)
	{
		if (pthread_mutex_init(&t->forks[i], NULL))
			return (1);
		if (pthread_mutex_init(&t->philos[i].meal_mutex, NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&t->print_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&t->stop_mutex, NULL))
		return (1);
	return (0);
}

/*
 ** taff sur la table de base de main
 ** malloc les tableau avce taille des struct * nbphilo
 ** protection en cas derreur de maloc
 ** i nitialisation des philosophe et des mutex avec protection
*/

int	init_table(t_table *t)
{
	t->stop = 0;
	t->philos = malloc(sizeof(t_philo) * t->a.nb_philo);
	t->forks = malloc(sizeof(pthread_mutex_t) * t->a.nb_philo);
	if (!t->philos || !t->forks)
	{
		free(t->philos);
		free(t->forks);
		return (1);
	}
	init_philos(t);
	if (init_mutexes(t))
	{
		free(t->philos);
		free(t->forks);
		return (1);
	}
	return (0);
}
