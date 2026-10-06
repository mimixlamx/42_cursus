#include "philo.h"

/*
 ** on regarde l'heure du dernier repas vs l'heure actuelle 
 ** si il est vivant 0 sinon 1 et tout coupe 
 ** set stop
 ** annonce de la mort
 ** unlock
*/

static int	is_dead(t_table *t, t_philo *p)
{
	long	last;

	pthread_mutex_lock(&p->meal_mutex);
	last = p->last_meal;
	pthread_mutex_unlock(&p->meal_mutex);
	if (get_time() - last < t->a.t_die)
		return (0);
	pthread_mutex_lock(&t->print_mutex);
	set_stop(t);
	printf("%ld %d died\n", get_time() - t->start, p->id);
	pthread_mutex_unlock(&t->print_mutex);
	return (1);
}

/*
 ** check si on doitr le faire si ya un 6eme arg quoi
 ** on verifie si ils ont tous manger au moins le bon nombres 
 ** non alors on continue oui on coupe
 ** set stop et return 1
*/

static int	all_full(t_table *t)
{
	int	i;
	int	full;

	if (t->a.must_eat == -1)
		return (0);
	i = 0;
	full = 0;
	while (i < t->a.nb_philo)
	{
		pthread_mutex_lock(&t->philos[i].meal_mutex);
		if (t->philos[i].meals_count >= t->a.must_eat)
			full++;
		pthread_mutex_unlock(&t->philos[i].meal_mutex);
		i++;
	}
	if (full < t->a.nb_philo)
		return (0);
	set_stop(t);
	return (1);
}

/*
 ** boucle de surveillance infinie sortie par return
 ** verifier si mort ou si tout le monde a assser manger
 ** pause 0.5ms et on relance
*/

void	monitor(t_table *t)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < t->a.nb_philo)
		{
			if (is_dead(t, &t->philos[i]))
				return ;
			i++;
		}
		if (all_full(t))
			return ;
		usleep(500);
	}
}
