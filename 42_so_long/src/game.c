/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   game.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/18 13:56:54 by mbruyere       #+#    #+#                */
/*   Updated: 2026/04/10 16:30:09 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_app *app)
{
	free_map(&app->check);
	if (app->img_wall)
		mlx_destroy_image(app->mlx, app->img_wall);
	if (app->img_background)
		mlx_destroy_image(app->mlx, app->img_background);
	if (app->img_player)
		mlx_destroy_image(app->mlx, app->img_player);
	if (app->img_collectible)
		mlx_destroy_image(app->mlx, app->img_collectible);
	if (app->img_exit)
		mlx_destroy_image(app->mlx, app->img_exit);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(0);
}

int	witch_key(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keycode == 65307)
		return (close_window(app), 1);
	else if (keycode == 119 || keycode == 65362)
		return (move_up((t_app *)param), 1);
	else if (keycode == 115 || keycode == 65364)
		return (move_down((t_app *)param), 1);
	else if (keycode == 97 || keycode == 65361)
		return (move_left((t_app *)param), 1);
	else if (keycode == 100 || keycode == 65363)
		return (move_right((t_app *)param), 1);
	else
		return (0);
}

int	load_image(t_app *app)
{
	app->img_background = mlx_xpm_file_to_image(app->mlx,
			"textures/background.xpm", &app->size, &app->size);
	app->img_wall = mlx_xpm_file_to_image(app->mlx, "textures/wall.xpm",
			&app->size, &app->size);
	app->img_player = mlx_xpm_file_to_image(app->mlx, "textures/suprawb.xpm",
			&app->size, &app->size);
	app->img_collectible = mlx_xpm_file_to_image(app->mlx,
			"textures/collectibles.xpm",
			&app->size, &app->size);
	app->img_exit = mlx_xpm_file_to_image(app->mlx, "textures/exit.xpm",
			&app->size, &app->size);
	if (!app->img_player || !app->img_background || !app->img_wall
		|| !app->img_collectible || !app->img_exit)
		return (ft_printf("Error\nxpm not ok"), 0);
	return (1);
}

int	launch_game(t_check *check)
{
	t_app	app;

	app.mlx = NULL;
	app.win = NULL;
	app.img_wall = NULL;
	app.img_background = NULL;
	app.img_player = NULL;
	app.img_collectible = NULL;
	app.img_exit = NULL;
	app.count_move = 0;
	app.collected = 0;
	app.check = *check;
	app.mlx = mlx_init();
	if (!app.mlx)
		return (0);
	app.size = 128;
	app.win = mlx_new_window(app.mlx, (128 * app.check.w),
			(128 * app.check.h), "Test MLX");
	if (load_image(&app) == 0)
		close_window(&app);
	put_image(&app);
	mlx_key_hook(app.win, witch_key, &app);
	mlx_hook(app.win, 17, 0, close_window, &app);
	mlx_loop(app.mlx);
	return (1);
}
