/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 06:55:57 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/14 15:10:35 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_map(t_map *s_map)
{
	int	i;

	if (!s_map)
		return ;
	if (s_map->map)
	{
		i = 0;
		while (s_map->map[i])
		{
			free(s_map->map[i]);
			i++;
		}
		free(s_map->map);
	}
	free(s_map);
}

void	free_imgs(t_game *s_game, void **img, int i)
{
	int	j;

	j = 0;
	ft_printf("Error\nFailed to load image %d\n", i);
	while (j < 5)
	{
		if (img[j] && j != i)
			mlx_destroy_image(s_game->mlx, img[j]);
		j++;
	}
}

void	exit_map(t_map *map)
{
	if (map)
		free_map(map);
	get_next_line(-1); //check this
	exit(1);
}

void	free_grid(char **grid)
{
	int i;

	i = 0;
	while (grid[i] != NULL)
		free(grid[i++]);
	free(grid);
	grid = NULL;
}

void	start_cleanup(t_game **s_game, t_map **s_map)
{
	free_map(*s_map);
	if (s_game)
	{
		if ((*s_game)->win_mlx)
			mlx_destroy_window((*s_game)->mlx, (*s_game)->win_mlx);
		if ((*s_game)->mlx)
		{
			mlx_destroy_display((*s_game)->mlx);
			free((*s_game)->mlx);
		}
		free(*s_game);
	}
	exit(1);
}
