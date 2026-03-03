#ifndef HEADER_H
# define HEADER_H
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include "./minilibx-linux-master/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./lib_ft/libft.h"
# define TILE_SIZE 64
typedef struct game_vars {
	char	**map;
	int		player_x;
	int		player_y;
	void	*mlx;
	void	*window;
	int		rows;
	int		cols;
	int		collects;
	int		move_counter;
	int		tile_size;
	int		window_width;
	int		window_height;
	void	*images[5];
} game;
bool	validate_reachability(game *x);
int		exit_game(game *s_game);
void	setup_hooks(game *s_game);
bool	check_map_size(game *s_game, int window_width, int window_height);
int		keyboard_handle(int key, game *s_game);
void	check_ber(const char *file_name, game *s_game);
void	free_map(char **map, int y);
void	checks(game *x);
void	render_map(game *x);
bool	location_check(char data, int rows, int cols);
#endif
