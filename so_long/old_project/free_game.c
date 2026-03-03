/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:48:51 by dana              #+#    #+#             */
/*   Updated: 2026/02/01 13:26:32 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_images(game *s_game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (s_game->images[i])
			mlx_destroy_image(s_game->mlx, s_game->images[i]);
		i++;
	}
}

void free_map(char **map, int rows)
{
	int i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(game *s_game)
{
	// Destroy all images
	free_images(s_game);

	// Destroy the window
	if (s_game->window)
		mlx_destroy_window(s_game->mlx, s_game->window);

	// Destroy display (only for Linux MiniLibX)
	mlx_destroy_display(s_game->mlx);

	// Free the map
	free_map(s_game->map, s_game->rows);
	free(s_game->mlx);

	// Free the game structure (if dynamically allocated)
	free(s_game);

	// Exit the program
	exit(EXIT_SUCCESS);
}
