/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   move.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mbruyere <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/18 12:52:34 by mbruyere       #+#    #+#                */
/*   Updated: 2026/03/18 15:58:08 by mbruyere       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_app *app)
{
	if (app->check.map[app->check.x - 1][app->check.y] != '1')
	{
		app->count_move++;
		ft_printf("move nbr : %d\n", app->count_move);
		if (app->check.map[app->check.x - 1][app->check.y] == 'C')
			app->collected++;
		else if (app->check.map[app->check.x - 1][app->check.y] == 'E')
		{
			if (app->collected == app->check.c)
				close_window(app);
			return ;
		}
		app->check.map[app->check.x - 1][app->check.y] = 'P';
		app->check.map[app->check.x][app->check.y] = '0';
		app->check.x = app->check.x - 1;
		mlx_clear_window(app->mlx, app->win);
		put_image(app);
	}
}

void	move_down(t_app *app)
{
	if (app->check.map[app->check.x + 1][app->check.y] != '1')
	{
		app->count_move++;
		ft_printf("move nbr : %d\n", app->count_move);
		if (app->check.map[app->check.x + 1][app->check.y] == 'C')
			app->collected++;
		else if (app->check.map[app->check.x + 1][app->check.y] == 'E')
		{
			if (app->collected == app->check.c)
				close_window(app);
			return ;
		}
		app->check.map[app->check.x + 1][app->check.y] = 'P';
		app->check.map[app->check.x][app->check.y] = '0';
		app->check.x = app->check.x + 1;
		mlx_clear_window(app->mlx, app->win);
		put_image(app);
	}
}

void	move_left(t_app *app)
{
	if (app->check.map[app->check.x][app->check.y - 1] != '1')
	{
		app->count_move++;
		ft_printf("move nbr : %d\n", app->count_move);
		if (app->check.map[app->check.x][app->check.y - 1] == 'C')
			app->collected++;
		else if (app->check.map[app->check.x][app->check.y - 1] == 'E')
		{
			if (app->collected == app->check.c)
				close_window(app);
			return ;
		}
		app->check.map[app->check.x][app->check.y - 1] = 'P';
		app->check.map[app->check.x][app->check.y] = '0';
		app->check.y = app->check.y - 1;
		mlx_clear_window(app->mlx, app->win);
		put_image(app);
	}
}

void	move_right(t_app *app)
{
	if (app->check.map[app->check.x][app->check.y + 1] != '1')
	{
		app->count_move++;
		ft_printf("move nbr : %d\n", app->count_move);
		if (app->check.map[app->check.x][app->check.y + 1] == 'C')
			app->collected++;
		else if (app->check.map[app->check.x][app->check.y + 1] == 'E')
		{
			if (app->collected == app->check.c)
				close_window(app);
			return ;
		}
		app->check.map[app->check.x][app->check.y + 1] = 'P';
		app->check.map[app->check.x][app->check.y] = '0';
		app->check.y = app->check.y + 1;
		mlx_clear_window(app->mlx, app->win);
		put_image(app);
	}
}
