/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:07:52 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/02/03 13:36:52 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	read_map_file(char *file_name)
{
	int	fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("%s\n", line);
		line = get_next_line(fd);
	}
	free(line);
	return (1);
}
