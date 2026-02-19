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
		mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(0);
}

int	witch_key(int keycode, void *param)
{
	if (keycode == 65307)
		return (close_window(param), 1);
	return (printf("not binded"), 0);
}

int	load_image(t_app *app)
{

	app->img_background = mlx_xpm_file_to_image(app->mlx, "background.xpm", &app->size, &app->size);
	app->img_wall = mlx_xpm_file_to_image(app->mlx, "wall.xpm", &app->size, &app->size);
	app->img_player = mlx_xpm_file_to_image(app->mlx, "test.xpm", &app->size, &app->size);
	if (!app->img_player || !app->img_background || !app->img_wall)
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
		return (1);
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
			y++;
		}
		y = 0;
		i++;
	}
	mlx_key_hook(app.win, witch_key, &app);
	mlx_hook(app.win, 17, 0, close_window, &app);
	mlx_loop(app.mlx);
	return (0);
}
