/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   so_long.h                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/02/12 13:52:09 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/12 11:54:34 by mbruyere       ########   odam.nl        */
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
# include "minilibx-linux/mlx.h"

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

typedef struct s_app
{
	void	*mlx;
	void	*win;
	void	*img_background;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	int		size;
	int		collected;
	t_check	check;
}	t_app;
int		test(t_check *check);
int		flood_fil_launch(t_check *check);
void	free_visited_map(t_check *check);
void	free_map(t_check *check);
void	move_up(t_app *app);
void	move_down(t_app *app);
void	move_left(t_app *app);
void	move_right(t_app *app);
void	put_image(t_app *app);
int		close_window(t_app *app);

/*
** end
*/
#endif
