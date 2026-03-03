#include "header.h"

bool **create_visited_array(int rows, int cols)
{
	int i;

	i = 0;
	bool **visited = malloc(rows * (sizeof(bool *)));
	while (i < rows)
	{
		visited[i] = ft_calloc(cols, sizeof(bool));
		i++;
	}
	return (visited);
}

void free_visited_array(bool **visited, int rows)
{
	int i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void dfs(game *s_game, bool **visited, int start_x, int start_y)
{
	int		x;
	int		y;
	int		cols;
	int		rows;

	x = start_x;
	y = start_y;
	cols = s_game->cols;
	rows = s_game->rows;
	if (x < 0 || y < 0 || x >= cols || y >= rows || s_game->map[y][x] == '1' || visited[y][x])
		return;
	visited[y][x] = true;
	dfs(s_game, visited, x + 1, y);
	dfs(s_game, visited, x - 1, y);
	dfs(s_game, visited, x, y + 1);
	dfs(s_game, visited, x, y - 1);
}
bool validate_reachability(game *s_game)
{
	int x;
	int	y;
	bool **visited;

	visited = create_visited_array(s_game->rows, s_game->cols);
	dfs(s_game, visited, s_game->player_x, s_game->player_y);
	y = 0;
	while(y < s_game->rows)
	{
		x = 0;
		while (x < s_game->cols)
		{
			if (s_game->map[y][x] == 'C' || s_game->map[y][x] == 'E')
				if(!visited[y][x])
				{
					free_visited_array(visited, s_game->rows);
					return (false);
				}
			x++;
		}
		y++;
	}
	free_visited_array(visited, s_game->rows);
	return (true);
}
