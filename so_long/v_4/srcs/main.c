/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:46:12 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/14 14:33:00 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit(1);
	map->map = NULL;
	map->rows = 0;
	map->cols = 0;
	map->p_start.x = 0;
	map->p_start.y = 0;
	map->exit_loc.x = 0;
	map->exit_loc.y = 0;
	map->to_collect = 0;
	map->collected = 0;
	return (map);
}

t_game	*init_game(t_map *s_map)
{
	t_game	*new;

	new = ft_calloc(1, sizeof(t_game));
	if (!new)
	{
		free_map(s_map);
		exit(1);
	}
	new->mlx = NULL;
	new->win_mlx = NULL;
	new->moves = 0;
	new->player_current = s_map->p_start;
	new->current = s_map;
	return (new);
}

int	main(int argc, char **argv)
{
	t_game	*s_game;
	t_map	*s_map;

	s_map = init_map();
	if (check_file(argc, argv[1]) < 0)
		exit_map(s_map);
	s_map->map = read_map(argv[1], &s_map);
	if (!s_map->map)
		exit_map(s_map);
	if (is_valid(&s_map) == 0)
		exit_map(s_map);
	s_game = init_game(s_map);
	if (!start(s_game, s_map))
		start_cleanup(&s_game, &s_map);
	mlx_key_hook(s_game->win_mlx, key_press, s_game);
	mlx_hook(s_game->win_mlx, 17, 0, close_window, s_game);
	mlx_loop(s_game->mlx);
	return (0);
}
