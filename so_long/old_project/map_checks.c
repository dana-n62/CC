#include "header.h"

bool check_shape(game *s_game)
{
	int i = 0;
	while (i < s_game->rows)
	{
		if ((int)ft_strlen(s_game->map[i]) != s_game->cols)
			return (false);
		i++;
	}
	return (true);
}

bool check_surrounding(game *s_game)
{
	int i;

	i = 1;
	while (i < s_game->cols)
	{
		if (s_game->map[0][i] != '1' || s_game->map[s_game->rows - 1][i] != '1')
			{
				printf("top and bottom error\n");
				return (false);
			}
		i++;
	}
	i = 0;
	while (i < s_game->rows)
	{
		if ((s_game->map[i][0] != '1') || (s_game->map[i][s_game->cols - 1] != '1'))
			return (false);
		i++;
	}
	return (true);
}

bool check_content(game *s_game)
{
	int i;
	int j;
	bool e;

	i = 0;
	s_game->collects = 0;
	while (i++ < (s_game->rows - 1))
	{
		j = 0;
		while (j++ < (s_game->cols - 1))
		{
			if (s_game->map[i][j] == 'C')
					s_game->collects++;
			if (s_game->map[i][j] == 'E')
				e = true;
		}
	}
	if (s_game->collects <= 0 || !e)
		return (false);
	return (true);
}
bool	check_map_size(game *s_game, int window_width, int window_height)
{
	int		map_width;
	int		map_height;

	map_width = s_game->cols * TILE_SIZE;
	map_height = s_game->rows * TILE_SIZE;
	if (map_width > window_width || map_height > window_height)
	{
		printf("Error: map too large for window!\n");
		return (false);
	}
	return (true);
}
void checks(game *s_game)
{
	if (check_shape(s_game) == false)
		{
			printf("error with size\n");
			exit(EXIT_FAILURE);
		}
	if (check_surrounding(s_game) == false)
	{
		printf("error with walls\n");
		exit(EXIT_FAILURE);
	}
	if (check_content(s_game) == false)
	{
		printf("error with content\n");
		exit(EXIT_FAILURE);
	}
}
