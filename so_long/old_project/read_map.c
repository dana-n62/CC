#include "header.h"

int	col_size(const char *file)
{
	int col_size = 0;
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (col_size == 0)
			col_size = ft_strlen(line) - 1;
		free(line);
	}
	free(line);
	close(fd);
	if (col_size <= 0)
		exit(EXIT_FAILURE);
	return (col_size);
}

int rows_number(const char *file)
{
	int rows_number;
	int fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	rows_number = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
			rows_number++;
			free(line);
	}
	free(line);
	close(fd);
	if (rows_number <= 0)
		exit(EXIT_FAILURE);
	return (rows_number);
}

int	read_map(const char *file_name, game *s_game)
{
	int		fd;
	char	*line = NULL;
	int		rows;

	fd = open(file_name, O_RDONLY);
    if (fd < 0)
			return(0);
	s_game->cols = col_size(file_name);
	s_game->rows = rows_number(file_name);
	rows = 0;
	s_game->map = malloc((s_game->rows + 1) * sizeof(char *));
 	if (!s_game->map)
			return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		s_game->map[rows] = line;
		rows++;
	}
	s_game->map[rows] = NULL;
	free(line);
	close(fd);
	checks(s_game);
	return (1);
}

void	check_ber(const char *file_name, game *s_game)
{
	int		start;

	start = (int)ft_strlen(file_name) - 4;
	if (ft_strncmp(file_name + start, ".ber", 4) == 0)
		read_map(file_name, s_game);
	else
		exit(EXIT_FAILURE);
}
