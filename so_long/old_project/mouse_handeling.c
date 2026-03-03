/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handeling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <dana@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:11:45 by dana              #+#    #+#             */
/*   Updated: 2025/02/07 16:47:19 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		close_window(game *s_game)
{
	mlx_destroy_window(s_game->mlx, s_game->window);
	exit(0);
	return(0);
}

int		resize_window(game *s_game, int click)
{
	int		new_height;
	int		new_width;

	if (click != 0)
		{
			mlx_key_hook(s_game->window, keyboard_handle, s_game);
			return (0);
		}
	mlx_get_screen_size(s_game->mlx, &new_width, &new_height);
//	if (new_width != s_game->window_width || new_height != s_game->window_height)
	{
		s_game->window_width = new_width;
		s_game->window_height = new_height;
		if((new_width / s_game->cols) < (new_height / s_game->rows))
			s_game->tile_size = new_width / s_game->cols;
		else
			s_game->tile_size = new_height / s_game->rows;
		mlx_clear_window(s_game->mlx, s_game->window);
		render_map(s_game);
	}
	return (0);
}

int		mouse_handle(int button, int x, int y, game *s_game)
{
	(void)x;
	(void)y;
	if (button == 1)
		close_window(s_game);
	return (0);
}

void	setup_hooks(game *s_game)
{
	mlx_hook(s_game->window, 17, 0, close_window, s_game);
	mlx_hook(s_game->window, 9, 1L << 21, resize_window, s_game);
	mlx_mouse_hook(s_game->window, mouse_handle, s_game);
}
