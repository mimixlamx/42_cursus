/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   routine.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/07 12:38:49 by mbruyere       #+#    #+#                */
/*   Updated: 2026/10/07 12:38:56 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 ** philo pair droite gauche
 ** philo impair gauche droite
 ** pour eviter les deadlock de prendre des fourchette qui bloque les autre
*/

static void	take_forks(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->right);
		print_status(p, "has taken a fork");
		pthread_mutex_lock(p->left);
	}
	else
	{
		pthread_mutex_lock(p->left);
		print_status(p, "has taken a fork");
		pthread_mutex_lock(p->right);
	}
	print_status(p, "has taken a fork");
}

/*
 ** lancer la prise de fork
 ** remettre le last meal a jour
 ** print is eating et le temps
 ** incremente le count de repas
 ** repose les fourchette
*/

static void	eat(t_philo *p)
{
	take_forks(p);
	pthread_mutex_lock(&p->meal_mutex);
	p->last_meal = get_time();
	pthread_mutex_unlock(&p->meal_mutex);
	print_status(p, "is eating");
	precise_sleep(p->table->a.t_eat, p->table);
	pthread_mutex_lock(&p->meal_mutex);
	p->meals_count++;
	pthread_mutex_unlock(&p->meal_mutex);
	pthread_mutex_unlock(p->left);
	pthread_mutex_unlock(p->right);
}

/*
 ** annonce quil think
 ** en cas de pair rien
 ** en cas de nombre impair attende un poil plus 1/3 de son cycle
 ** le but est de laisser sa chance a un autre
*/

static void	think(t_philo *p)
{
	long	t_think;

	print_status(p, "is thinking");
	if (p->table->a.nb_philo % 2 == 0)
		return ;
	t_think = p->table->a.t_eat * 2 - p->table->a.t_sleep;
	if (t_think > 0)
		precise_sleep(t_think / 2, p->table);
}

/*
 ** prend sa seule fourchette et l'annonce
 ** il attend de mourir et meurt
*/

static void	*lonely_philo(t_philo *p)
{
	pthread_mutex_lock(p->left);
	print_status(p, "has taken a fork");
	precise_sleep(p->table->a.t_die * 2, p->table);
	pthread_mutex_unlock(p->left);
	return (NULL);
}

/*
 ** chaque thread lance ca
 ** gestion du cas philo seul risque de bug double fourchette 0
 ** les paires attende et les im:paires se lancent en premier
 ** tant que pas stopped on lance la routine manger dormir penser
*/

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->table->a.nb_philo == 1)
		return (lonely_philo(p));
	if (p->id % 2 == 0)
		precise_sleep(p->table->a.t_eat / 2, p->table);
	while (!is_stopped(p->table))
	{
		eat(p);
		print_status(p, "is sleeping");
		precise_sleep(p->table->a.t_sleep, p->table);
		think(p);
	}
	return (NULL);
}
