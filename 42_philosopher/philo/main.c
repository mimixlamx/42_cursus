#include "philo.h"

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
