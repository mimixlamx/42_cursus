/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   time.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/07 12:39:18 by mbruyere       #+#    #+#                */
/*   Updated: 2026/10/07 12:39:20 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 ** time.h 
 ** recup le temps depuis 1970 en secondes et les microsecondes de plus 
 ** tv sec tv usec remplis via gettimeofday dans la struct tv
*/

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

/*
 ** recup l'heure  puis bvoucle troute les 0.5ms
 ** tant que le tempms ecxoulé est strictement inferieur a ms on boucle
 ** sauf si stopped
*/

void	precise_sleep(long ms, t_table *t)
{
	long	start;

	start = get_time();
	while (!is_stopped(t) && get_time() - start < ms)
		usleep(500);
}
