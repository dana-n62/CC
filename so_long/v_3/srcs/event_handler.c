/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:04:31 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/03 04:24:51 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_map(t_map *game)
{
	int	i;

	if (!game)
		return ;
	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	free(game);
}

int	close_window(void *param)
{
	t_game	*s_game;

	s_game = (t_game *)param;
	free_map(s_game->current);
	mlx_destroy_image(s_game->mlx, s_game->game.w);
	mlx_destroy_image(s_game->mlx, s_game->game.f);
	mlx_destroy_image(s_game->mlx, s_game->game.c);
	mlx_destroy_image(s_game->mlx, s_game->game.p);
	mlx_destroy_image(s_game->mlx, s_game->game.e);
	mlx_destroy_window(s_game->mlx, s_game->win_mlx);
	mlx_destroy_display(s_game->mlx);
	free(s_game->mlx);
	free(s_game);
	exit (0);
}

int	key_press(int key_press, void *param)
{
	t_game	*s_game;

	s_game = (t_game *)param;
	if (key_press == 65307)
		close_window(param);
	else if (key_press == 65362 || key_press == 65361)
		move_player(s_game, key_press);
	else if (key_press == 65363 || key_press == 65364)
		move_player(s_game, key_press);
	else if (key_press == 97 || key_press == 119)
		move_player(s_game, key_press);
	else if (key_press == 115 || key_press == 100)
		move_player(s_game, key_press);
	return (1);
}
