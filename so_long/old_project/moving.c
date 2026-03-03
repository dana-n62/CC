#include "header.h"

void	player_move_action(game *s_game, int new_x, int new_y)
{
	s_game->move_counter++;
	printf("%d\n", s_game->move_counter);
	s_game->map[s_game->player_y][s_game->player_x] = '0';
	s_game->player_y = new_y;
	s_game->player_x = new_x;
	s_game->map[s_game->player_y][s_game->player_x] = 'P';
}

void	move_player(game *s_game, int new_x, int new_y)
{
	if ((s_game->map[new_y][new_x] == '1') || new_y < 0 || new_x < 0)
		return;
	if (s_game->map[new_y][new_x] == 'C')
		s_game->collects--;
	if (s_game->map[new_y][new_x] == 'E')
	{
		if (s_game->collects == 0)
			{
				player_move_action(s_game, new_x, new_y);
				printf("YOU WON!!\n");
				exit(EXIT_SUCCESS);
			}
			else
			{
				printf("finish the collectables!\n");
				return;
			}
	}
	player_move_action(s_game, new_x, new_y);
	render_map(s_game);
}

int keyboard_handle(int key, game *s_game)
{
	if (key == 65307)
		exit(0);
	if (key == 65361 || key == 97)
		move_player(s_game, s_game->player_x - 1, s_game->player_y);
	if (key == 65362 || key == 119)
		move_player(s_game, s_game->player_x, s_game->player_y - 1);
	if (key == 65363 || key == 100)
		move_player(s_game, s_game->player_x + 1, s_game->player_y);
	if (key == 65364 || key == 115)
		move_player(s_game, s_game->player_x, s_game->player_y + 1);
	return (0);
}
