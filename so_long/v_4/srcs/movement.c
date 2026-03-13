/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:57:41 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/03 11:10:58 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_player(t_game *s_game, int keycode)
{
	int	new_x;
	int	new_y;

	new_x = s_game->player_current.x;
	new_y = s_game->player_current.y;
	if (keycode == 119 || keycode == 65362)
		new_x--;
	else if (keycode == 97 || keycode == 65361)
		new_y--;
	else if (keycode == 115 || keycode == 65364)
		new_x++;
	else if (keycode == 100 || keycode == 65363)
		new_y++;
	if (can_move(s_game, new_x, new_y))
	{
		s_game->player_current.x = new_x;
		s_game->player_current.y = new_y;
		s_game->moves++;
		ft_printf("%d\n", s_game->moves);
		render_map(s_game);
	}
}

int	can_move(t_game *s_game, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (x >= s_game->current->rows || y >= s_game->current->cols)
		return (0);
	if (s_game->current->map[x][y] == '1')
		return (0);
	if (s_game->current->map[x][y] == 'C')
	{
		s_game->current->collected++;
		s_game->current->map[x][y] = '0';
	}
	if (s_game->current->map[x][y] == 'E')
	{
		if (s_game->current->collected == s_game->current->to_collect)
		{
			ft_printf("YOU WON!!\n");
			close_window(s_game);
		}
		else
		{
			ft_printf("Finish all collectables first\n");
			return (0);
		}
	}
	return (1);
}
