#include "header.h"

void	load_images(void *mlx, void **images, int *img_width)
{
	int		img_height;
	int		i;

	images[0] = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", img_width, &img_height);
	images[1] = mlx_xpm_file_to_image(mlx, "./images/floor.xpm", img_width, &img_height);
	images[2] = mlx_xpm_file_to_image(mlx, "./images/player.xpm", img_width, &img_height);
	images[3] = mlx_xpm_file_to_image(mlx, "./images/cup.xpm", img_width, &img_height);
	images[4] = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", img_width, &img_height);
	i = 0;
	while (i < 5)
	{
		if (!images[i])
		{
			while (i >= 0)
			{
				mlx_destroy_image(mlx, images[i]);
				i--;
			}
			printf("Error loading image\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	put_pixel(game *s_game, int row, int col)
{
	int	x;
	int	y;

	x = col * s_game->tile_size;
	y = row * s_game->tile_size;
	if (s_game->map[row][col] == '1')
		mlx_put_image_to_window(s_game->mlx, s_game->window, s_game->images[0], x, y);
	else if (s_game->map[row][col] == '0')
		mlx_put_image_to_window(s_game->mlx, s_game->window, s_game->images[1], x, y);
	else if (s_game->map[row][col] == 'P')
		mlx_put_image_to_window(s_game->mlx, s_game->window, s_game->images[2], x, y);
	else if (s_game->map[row][col] == 'C')
		mlx_put_image_to_window(s_game->mlx, s_game->window, s_game->images[3], x, y);
	else if (s_game->map[row][col] == 'E')
		mlx_put_image_to_window(s_game->mlx, s_game->window, s_game->images[4], x, y);
}

void	put_images(game *s_game, int row, int col)
{
	if (row >= s_game->rows)
		return ;
	if (col >= s_game->cols)
	{
		put_images(s_game, row + 1, 0);
		return ;
	}
	put_pixel(s_game, row, col);
	put_images(s_game, row, col + 1);
}

void	render_map(game *s_game)
{
	int		window_width;
	int		window_height;
	int		img_width;

	mlx_get_screen_size(s_game->mlx, &window_width, &window_height);
	s_game->window_width = window_width;
	s_game->window_height = window_height;
	if (s_game->cols == 0 || s_game->rows == 0)
	{
		printf("Error: Map size is invalid!\n");
		exit(EXIT_FAILURE);
	}
	load_images(s_game->mlx, s_game->images, &img_width);
	s_game->tile_size  = img_width;
	put_images(s_game, 0, 0);
}
