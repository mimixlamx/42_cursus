/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   so_long.h                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/02/12 13:52:09 by mbruyere       #+#    #+#                */
/*   Updated: 2026/02/12 14:29:46 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
/*
** double define protection
*/
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_check
{
	char	**map;
	char	**visited_map;
	int		w;
	int		h;
	int		x;
	int		y;
	int		p;
	int		e;
	int		c;
	int		found_c;
	int		found_e;
}	t_check;

int	flood_fil_launch(t_check *check);

/*
** end
*/
#endif
