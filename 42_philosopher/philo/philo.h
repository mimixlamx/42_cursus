/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   philo.h                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/07 12:39:35 by mbruyere       #+#    #+#                */
/*   Updated: 2026/10/07 12:39:37 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	int	nb_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	must_eat;
}	t_args;

typedef struct s_table	t_table;

/*
 ** mutex = protection multi acces
 ** plusieur niveau : sur le philo ou sur la table
*/

typedef struct s_philo
{
	int				id;
	int				meals_count;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	meal_mutex;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	t_args			a;
	long			start;
	int				stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
	t_philo			*philos;
}	t_table;

int		parse_args(int argc, char **argv, t_args *a);
void	precise_sleep(long ms, t_table *t);
long	get_time(void);
int		init_table(t_table *t);
void	cleanup(t_table *t);
int		is_stopped(t_table *t);
void	set_stop(t_table *t);
void	print_status(t_philo *p, char *msg);
void	*routine(void *arg);
void	monitor(t_table *t);

#endif
