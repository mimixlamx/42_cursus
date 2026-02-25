#include "so_long.h"

void	move_up(t_app *app)
{
	if (app->check.map[app->check.x - 1][app->check.y] != 1)
	{
		app->check.map[app->check.x - 1][app->check.y] == 'P';
		app->check.map[app->check.x][app->check.y] == '0';
	}
}
