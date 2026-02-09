#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_app
{
    void	*mlx;
    void	*win;
	void	*img_player;
	int		size;
}   t_app;

int close_window(void *param)
{
	t_app *app;

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
		return (close_window(param),0);
}

int main(void)
{
	t_app app;

	app.size = 128;
	app.mlx = mlx_init();
	app.img_player = mlx_xpm_file_to_image(app.mlx, "supra.xpm", &app.size, &app.size);
	if (!app.img_player)
		return(1);
	app.win = mlx_new_window(app.mlx, 800, 600, "Test MLX");
	mlx_put_image_to_window(app.mlx, app.win, app.img_player, 0, 0);
	mlx_key_hook(app.win, witch_key, &app);
	mlx_hook(app.win, 17, 0, close_window, &app);
	mlx_loop(app.mlx);
	return (0);
}
