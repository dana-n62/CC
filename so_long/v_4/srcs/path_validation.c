/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:11:11 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/02 16:22:26 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	validate_path(t_map **game)
{
	int	**path_map;
	int	reach;
	int	rows;
	int	cols;

	path_map = create_visited((*game)->rows, (*game)->cols);
	if (!path_map)
		return (0);
	rows = (*game)->rows;
	cols = (*game)->cols;
	flood_fill(game, path_map, (*game)->p_start.x, (*game)->p_start.y);
	reach = check_reach((*game)->map, path_map, cols, rows);
	free_visited(path_map, (*game)->rows);
	return (reach);
}

void	flood_fill(t_map **game, int **visited, int x, int y)
{
	int	rows;
	int	cols;

	rows = (*game)->rows;
	cols = (*game)->cols;
	if (y < 0 || y >= cols || x < 0 || x >= rows)
		return ;
	if (visited[x][y] == 1)
		return ;
	if ((*game)->map[x][y] == '1')
		return ;
	visited[x][y] = 1;
	flood_fill(game, visited, x, y + 1);
	flood_fill(game, visited, x, y - 1);
	flood_fill(game, visited, x + 1, y);
	flood_fill(game, visited, x - 1, y);
}

int	**create_visited(int rows, int cols)
{
	int	**visited;
	int	i;

	visited = ft_calloc(rows, sizeof(int *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		visited[i] = ft_calloc(cols, sizeof(int));
		if (!visited[i])
		{
			free_visited(visited, i);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

void	free_visited(int **visited, int rows)
{
	int	i;

	if (visited == NULL)
		return ;
	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	check_reach(char **map, int **visited, int cols, int rows)
{
	int	x;
	int	y;

	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			if (map[x][y] == 'C')
			{
				if (visited[x][y] == 0)
					return (0);
			}
			if (map[x][y] == 'E')
			{
				if (visited[x][y] == 0)
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}
