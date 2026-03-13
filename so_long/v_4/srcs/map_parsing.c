/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:44:30 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/03 04:37:44 by Dana Nour        ###   ########.fr       */
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
//still reachable and invalid read 
//when doing line = NULL;//get_next_line(fd);
void	count_lines(char *file_name, t_map **s_map)
{
	char	*line;
	int		fd;

	//still reachable and invalid read 
	//when doing line = NULL;//get_next_line(fd);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		free(*s_map);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		(*s_map)->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
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

char	**read_map(char *file_name, t_map **s_map)
{
	int		fd;
	char	**grid;
	int		i;

	count_lines(file_name, s_map);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	grid = malloc(((*s_map)->rows + 1) * sizeof(char *));
	if (!grid)
	{
		//free still reachable when the malloc fails
		close(fd);
		exit(1);
	}
	i = -1;
	while (++i < (*s_map)->rows)
	{
		grid[i] = get_next_line(fd); // still reachable
		if (!process_line(grid[i], s_map, i))
			break ;
	}
	free(get_next_line(fd));
	grid[i] = NULL;
	close(fd);
	return (grid);
}
