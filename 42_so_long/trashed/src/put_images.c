/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   put_images.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/18 13:20:37 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/10 16:14:59 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	put_image_last(t_app *app)
{
	int	i;
	int	y;

	i = 0;
	while (i < app->check.h)
	{
		y = 0;
		while (y < app->check.w)
		{
			if (app->check.map[i][y] == 'C')
				mlx_put_image_to_window(app->mlx, app->win,
					app->img_collectible, app->size * y, app->size * i);
			if (app->check.map[i][y] == 'E')
				mlx_put_image_to_window(app->mlx, app->win, app->img_exit,
					app->size * y, app->size * i);
			y++;
		}
		i++;
	}
}

void	put_image(t_app *app)
{
	int	i;
	int	y;

	i = 0;
	while (i < app->check.h)
	{
		y = 0;
		while (y < app->check.w)
		{
			if (app->check.map[i][y] == '1')
				mlx_put_image_to_window(app->mlx, app->win, app->img_wall,
					app->size * y, app->size * i);
			if (app->check.map[i][y] == 'P')
				mlx_put_image_to_window(app->mlx, app->win, app->img_player,
					app->size * y, app->size * i);
			if (app->check.map[i][y] == '0')
				mlx_put_image_to_window(app->mlx, app->win, app->img_background,
					app->size * y, app->size * i);
			y++;
		}
		i++;
	}
	put_image_last(app);
}
