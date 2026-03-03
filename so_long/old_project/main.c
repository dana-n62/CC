#include "header.h"

/* void	enable_window_resizing(game *s_game)
{
	Display		*display;
	Window		win;
	XSizeHints	hints;

	display = mlx_get;
	if (!display)
		return ;
	win = (Window)s_game->window;
	hints.flags = PMinSize | PMaxSize;
	hints.min_width = 300;  // Set a reasonable min width
	hints.min_height = 200; // Set a reasonable min height
	hints.max_width = 1920; // Set max width
	hints.max_height = 1080; // Set max height
	XSetWMNormalHints(display, win, &hints);
	XCloseDisplay(display);
} */

int		find_player(game *x)
{
	int		rows;
	int		cols;

	rows = 1;
	while (rows < x->rows)
	{
		cols = 1;
		while (cols < x->cols)
		{
			if (x->map[rows][cols] == 'P')
			{
				x->player_x = cols;
				x->player_y = rows;
				return (1);
			}
			cols++;
		}
		rows++;
	}
	return (0);
}
void	check_validity(int return_value, game *s_game)
{
	if (!return_value)
	{
		free_map(s_game->map, s_game->rows);
		exit(EXIT_FAILURE);
	}
}
int main ()
{
	game so_long;
	so_long.move_counter = 0;
	so_long.mlx = mlx_init();
	if (!so_long.mlx)
		exit(EXIT_FAILURE);
	check_ber("map.ber", &so_long);
	check_validity(find_player(&so_long), &so_long);
	check_validity(validate_reachability(&so_long), &so_long);
	so_long.window = mlx_new_window(so_long.mlx, so_long.cols * TILE_SIZE, so_long.rows * TILE_SIZE, "game");
	if (!so_long.window)
		{
			free_map(so_long.map, so_long.rows);
			free(so_long.mlx);
			exit(EXIT_FAILURE);
		}
	//enable_window_resizing(&so_long);
	render_map(&so_long);
	mlx_key_hook(so_long.window, keyboard_handle, &so_long);
	setup_hooks(&so_long);
	mlx_loop(so_long.mlx);
	exit_game(&so_long);
	return (0);
}
