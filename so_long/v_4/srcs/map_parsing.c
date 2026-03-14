/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:44:30 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/14 15:11:55 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_file(int argc, char *file_name)
{
	int	start;

	if (argc != 2 || !file_name)
	{
		ft_printf("Error\nWrong number of arguments (only one file)\n");
		return (-1);
	}
	start = ft_strlen(file_name) - 4;
	if (start < 1 || ft_strncmp(file_name + start, ".ber", 4) != 0)
	{
		ft_printf("Error\nInvalid file extension\n");
		return (-1);
	}
	return (0);
}

int	count_lines(char *file_name, t_map **s_map)
{
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!(line = get_next_line(fd)))
	{
		close(fd);
		return (0);
	}
	while (line)
	{
		(*s_map)->rows++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	free(line);
	get_next_line(-1);
	close(fd);
	return (1);
}

int	process_line(char *line, t_map **s_map, int i)
{
	int	j;

	if (!line)
		return (0);
	j = 0;
	while (line[j] && line[j] != '\n')
		j++;
	if (line[j] == '\n')
		line[j] = '\0';
	if (i == 0)
		(*s_map)->cols = j;
	return (1);
}

static int	fill_grid(int fd, char **grid, t_map **s_map)
{
	int	i;

	i = -1;
	while (++i < (*s_map)->rows)
	{
		grid[i] = get_next_line(fd);
		if (!grid[i] || !process_line(grid[i], s_map, i))
		{
			free_grid(grid);
			free(get_next_line(fd));
			return (0);
		}
	}
	free(get_next_line(fd));
	grid[i] = NULL;
	return (1);
}

char	**read_map(char *file_name, t_map **s_map)
{
	int		fd;
	char	**grid;

	if (count_lines(file_name, s_map) == 0)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	grid = ft_calloc(((*s_map)->rows + 1), sizeof(char *));
	if (!grid)
	{
		close(fd);
		return (NULL);
	}
	if (!fill_grid(fd, grid, s_map))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (grid);
}
