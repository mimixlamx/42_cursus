/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/07 12:38:08 by mbruyere       #+#    #+#                */
/*   Updated: 2026/10/07 13:02:06 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 ** heure ed depart pour mise a 0 des last meal 
 ** creation d'un thread par philo qui va lancer la routine 
 ** une fois les thread ok le thread principal passe a la surveillance
*/

static int	launch(t_table *t)
{
	int	i;

	t->start = get_time();
	i = 0;
	while (i < t->a.nb_philo)
	{
		t->philos[i].last_meal = t->start;
		i++;
	}
	i = 0;
	while (i < t->a.nb_philo)
	{
		if (pthread_create(&t->philos[i].thread, NULL,
				&routine, &t->philos[i]))
		{
			set_stop(t);
			return (i);
		}
		i++;
	}
	monitor(t);
	return (i);
}

/*
 ** si les argument sont mauvais error idem pour l'initialisation
 ** creation de nbphilo thread avec launch
 ** attente avec join de chaque thread
 ** netoyage avant fermeture
*/

int	main(int argc, char **argv)
{
	t_table	t;
	int		created;
	int		i;

	if (parse_args(argc, argv, &t.a))
		return (write(2, "Error: invalid arguments\n", 25), 1);
	if (init_table(&t))
		return (write(2, "Error: init failed\n", 19), 1);
	created = launch(&t);
	i = 0;
	while (i < created)
	{
		pthread_join(t.philos[i].thread, NULL);
		i++;
	}
	cleanup(&t);
	return (0);
}
