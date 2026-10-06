#include "philo.h"

/*
 ** tout ca est appeler a plusieur reprise
 ** plu simple d'en faire des fonctions
*/

/*
 ** lire stop si la surveillance ne lit pas déja
 ** copie la valeur pour eviter une modif entre deux execution
 ** unlock et return de la value
*/

int	is_stopped(t_table *t)
{
	int	ret;

	pthread_mutex_lock(&t->stop_mutex);
	ret = t->stop;
	pthread_mutex_unlock(&t->stop_mutex);
	return (ret);
}

/*
 ** lock set stop a 0 et unlock
 ** appeler en cas de mort ou de nombre de repas ok
*/

void	set_stop(t_table *t)
{
	pthread_mutex_lock(&t->stop_mutex);
	t->stop = 1;
	pthread_mutex_unlock(&t->stop_mutex);
}

/*
 ** verou ecriture pour ne pas mélanger
 ** si stop on affiche rien sinon on affiche 
 ** print time, id philo, mesage
*/

void	print_status(t_philo *p, char *msg)
{
	pthread_mutex_lock(&p->table->print_mutex);
	if (!is_stopped(p->table))
		printf("%ld %d %s\n", get_time() - p->table->start, p->id, msg);
	pthread_mutex_unlock(&p->table->print_mutex);
}
