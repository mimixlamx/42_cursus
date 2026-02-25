/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   test.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/02/10 14:27:53 by mbruyere       #+#    #+#                */
/*   Updated: 2026/02/10 14:29:57 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	t_app	*app;

	app = (t_app *) param;
	if (app->win)
	//destroy imqge ?
		mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(0);
}

int	witch_key(int keycode, void *param)
{
	if (keycode == 65307)
		return (close_window(param), 1);
	if (keycode == 122 || keycode == 65362)
		return (move_up((t_app *)param), 1);
/*
	if (keycode == 115 || keycode == 65364)
		return (move_down((t_app *)param), 1);
	if (keycode == 113 || keycode == 65361)
		return (move_left((t_app *)param), 1);
	if (keycode == 100 || keycode == 65363)
		return (move_right((t_app *)param), 1);
*/
else
		return (printf("not binded"), 0);
}

int	load_image(t_app *app)
{
	app->img_background = mlx_xpm_file_to_image(app->mlx, "background.xpm", &app->size, &app->size);
	app->img_wall = mlx_xpm_file_to_image(app->mlx, "wall.xpm", &app->size, &app->size);
	app->img_player = mlx_xpm_file_to_image(app->mlx, "suprawb.xpm", &app->size, &app->size);
	app->img_collectible = mlx_xpm_file_to_image(app->mlx, "collectibles.xpm", &app->size, &app->size);
	app->img_exit = mlx_xpm_file_to_image(app->mlx, "exit.xpm", &app->size, &app->size);
	if (!app->img_player || !app->img_background || !app->img_wall|| !app->img_collectible || !app->img_exit)
		return (printf("xpm not ok"), 0);
	return (1);
}

int	test(t_check *check)
{
	t_app	app;
	int	i;
	int	y;

	app.check = *check;
	i = 0;
	y = 0;
	while (app.check.map[i])// debug while 
	{
		printf ("map[%d] = %s\n", i, app.check.map[i]);
		i++;
	}
	i = 0;
	app.mlx = mlx_init();
	app.size = 128;
	printf("h =%d\n", app.check.h);
	app.win = mlx_new_window(app.mlx, (128 * app.check.w), (128 * app.check.h), "Test MLX");
	if (load_image(&app) == 0)
		return (0);
	printf("all image ok\n");
	while (i < app.check.h)
	{
		while (y < app.check.w)
		{
			if (app.check.map[i][y] == '1')
				mlx_put_image_to_window(app.mlx, app.win, app.img_wall, app.size * y, app.size *i);
			if (app.check.map[i][y] == 'P')
				mlx_put_image_to_window(app.mlx, app.win, app.img_player, app.size * y, app.size *i);
			if (app.check.map[i][y] == '0')
				mlx_put_image_to_window(app.mlx, app.win, app.img_background, app.size * y, app.size *i);
			if (app.check.map[i][y] == 'C')
				mlx_put_image_to_window(app.mlx, app.win, app.img_collectible, app.size * y, app.size *i);
			if (app.check.map[i][y] == 'E')
				mlx_put_image_to_window(app.mlx, app.win, app.img_exit, app.size * y, app.size *i);
			y++;
		}
		y = 0;
		i++;
	}
	mlx_key_hook(app.win, witch_key, &app);
	mlx_hook(app.win, 17, 0, close_window, &app);
	mlx_loop(app.mlx);
	return (1);
}
