/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:11:09 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/03 04:28:19 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	mlx_start(t_game *s_game, int rows, int cols)
{
	int	width;
	int	height;

	s_game->mlx = mlx_init();
	if (!s_game->mlx)
		return (0);
	width = cols * TILE_SIZE;
	height = rows * TILE_SIZE;
	s_game->win_mlx = mlx_new_window(s_game->mlx, width, height, "new game");
	if (!s_game->win_mlx)
		return (0);
	return (1);
}

int	load_images(t_game *s_game)
{
	int		width;
	int		height;
	void	*img[5];
	int		i;

	img[2] = mlx_xpm_file_to_image(s_game->mlx, "img/cup.xpm", &width, &height);
	img[1] = mlx_xpm_file_to_image(s_game->mlx, "img/wal.xpm", &width, &height);
	img[0] = mlx_xpm_file_to_image(s_game->mlx, "img/flr.xpm", &width, &height);
	img[3] = mlx_xpm_file_to_image(s_game->mlx, "img/plr.xpm", &width, &height);
	img[4] = mlx_xpm_file_to_image(s_game->mlx, "img/ext.xpm", &width, &height);
	i = 0;
	while (i < 5)
	{
		if (!img[i++])
		{
			ft_printf("Error loading exit\n");
			return (0);
		}
	}
	s_game->game.c = img[2];
	s_game->game.w = img[1];
	s_game->game.f = img[0];
	s_game->game.p = img[3];
	s_game->game.e = img[4];
	return (1);
}

void	render_map(t_game *g)
{
	int	x;
	int	y;
	int	px;
	int	py;

	x = -1;
	while (++x < g->current->rows)
	{
		y = -1;
		while (++y < g->current->cols)
		{
			px = y * TILE_SIZE;
			py = x * TILE_SIZE;
			if (g->current->map[x][y] == '1')
				mlx_put_image_to_window(g->mlx, g->win_mlx, g->game.w, px, py);
			else if (x == g->player_current.x && y == g->player_current.y)
				mlx_put_image_to_window(g->mlx, g->win_mlx, g->game.p, px, py);
			else if (g->current->map[x][y] == 'C')
				mlx_put_image_to_window(g->mlx, g->win_mlx, g->game.c, px, py);
			else if (g->current->map[x][y] == 'E')
				mlx_put_image_to_window(g->mlx, g->win_mlx, g->game.e, px, py);
			else
				mlx_put_image_to_window(g->mlx, g->win_mlx, g->game.f, px, py);
		}
	}
}

void	start(t_game *s_game, t_map *s_map)
{
	if (!mlx_start(s_game, s_map->rows, s_map->cols))
		return ;
	if (!load_images(s_game))
		return ;
	render_map(s_game);
}
