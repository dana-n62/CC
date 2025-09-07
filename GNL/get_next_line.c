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

static char	*find_new_line(char **remaining, char *current_read)
{
	char	*new_line;
	size_t	i;
	size_t	source_size;

	i = 0;
	source_size = ft_strlen(current_read);
	while (i < BUFFER_SIZE && current_read[i] != '\0')
	{
		if (current_read[i] == '\n')
		{
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
		}
		i++;
	}
	return (current_read);
}

char	*get_next_line(int fd)
{
	static char	*remainig_data = NULL;
	char		*read_data;
	ssize_t		read_bytes;

	read_data = malloc(BUFFER_SIZE + 1);
	if (!read_data)
		return (NULL);
	read_bytes = read(fd, read_data, BUFFER_SIZE);
	if (read_bytes > 0)
	{
		read_data[BUFFER_SIZE + 1] = '\0';
		read_data = find_new_line(&remainig_data, read_data);
	}
	else
	{
		free(read_data);
		free(remainig_data);
		return (NULL);
	}
	return (read_data);
}
