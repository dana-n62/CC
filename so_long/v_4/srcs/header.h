/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:25:59 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/03 04:17:54 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../GNL/get_next_line.h"
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define TILE_SIZE	64

typedef struct t_img
{
	void	*w;
	void	*f;
	void	*p;
	void	*c;
	void	*e;
}	t_img;

typedef struct loc_data
{
	int	x;
	int	y;
}	t_location;

typedef struct t_map
{
	char			**map;
	int				cols;
	int				rows;
	t_location		p_start;
	t_location		exit_loc;
	int				to_collect;
	int				collected;
}	t_map;

typedef struct t_game
{
	void		*mlx;
	void		*win_mlx;
	t_img		game;
	t_map		*current;
	t_location	player_current;
	int			moves;
}	t_game;

int			check_file(int argc, char *file_name);
char		**read_map(char *file_name, t_map **s_map);
int			is_valid(t_map **game);
int			validate_path(t_map **game);
void		flood_fill(t_map **game, int **visited, int x, int y);
int			**create_visited(int rows, int cols);
void		free_visited(int **visited, int rows);
int			check_reach(char **map, int **visited, int cols, int rows);
void		render_map(t_game *s_game);
int			load_images(t_game *s_game);
int			mlx_start(t_game *s_game, int rows, int cols);
int			start(t_game *s_game, t_map *s_map);
void		free_map(t_map *game);
int			close_window(void *param);
int			key_press(int key_press, void *param);
void		move_player(t_game *s_game, int keycode);
int			can_move(t_game *s_game, int x, int y);
void		free_imgs(t_game *s_game, void **img, int i);
#endif
