#include "philo.h"

/*
 ** free des maloc
 ** destroy des init mutex
 ** litteralement cleanup de l'init
*/
void	cleanup(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->a.nb_philo)
	{
		pthread_mutex_destroy(&t->forks[i]);
		pthread_mutex_destroy(&t->philos[i].meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&t->print_mutex);
	pthread_mutex_destroy(&t->stop_mutex);
	free(t->philos);
	free(t->forks);
}
