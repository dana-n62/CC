/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:35 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/03 10:00:21 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*find_line(int fd, ssize_t read_bytes, char **remaining)
{
	char	*found;
	char	*line;
	size_t	i;
	
	found = NULL;
	i = 0;
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (read_bytes > 0 || *remaining)
	{
		if (*remaining)
			i = ft_strchr(*remaining, '\n');
		if (i > 0)
		{
<<<<<<< HEAD
			if (*remaining == NULL)
			{
				*remaining = malloc(i + 1);
				if (!*remaining)
					return (NULL);
				ft_strlcpy(*remaining, current_read + i, source_size - i);
			}
			else
				ft_strlcat(*remaining, current_read + i, source_size - i);
			new_line = malloc(i + 1);
			if (!new_line)
				return (NULL);
			ft_strlcpy(new_line, current_read, i + 1);
			return (new_line);
=======
			found = malloc(i + 1);
			if (!found)
				return (NULL);
			ft_memmove(found, *remaining, i + 1);
			ft_memmove(*remaining, *remaining + i, ft_strlen(*remaining));
			free(line);
			return (found);
>>>>>>> 366ce06 (updated the whole work)
		}
		else
			*remaining = ft_strjoin(*remaining, line);
		read_bytes = read(fd, line, BUFFER_SIZE);
	}
	free(line);
	free(found);
	return (NULL);
}

char	*get_next_line(int fd)
{
<<<<<<< HEAD
	static char	*remainig_data = NULL;
	char		*read_data;
	ssize_t		read_bytes;

	read_data = malloc(BUFFER_SIZE + 1);
	if (!read_data)
=======
	static char	*remaining_data;
	ssize_t	read_bytes;
	char	*read_line;
	
	read_line = malloc(BUFFER_SIZE + 1);
	if (!read_line)
>>>>>>> 366ce06 (updated the whole work)
		return (NULL);
	read_bytes = read(fd, read_line, BUFFER_SIZE);
	if (read_bytes > 0 || remaining_data)
		read_line = find_line(fd, read_bytes, &remaining_data);
	if (read_bytes <= 0 && remaining_data == NULL)
	{
		free(read_line);
		return (NULL);
	}
	return (read_line);
}