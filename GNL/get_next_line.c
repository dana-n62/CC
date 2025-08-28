/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:35 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/28 12:28:35 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*find_new_line(char **remaining, char *current_read, int fd)
{
	char	*new_line;
	size_t	i;
	size_t	size;

	i = 0;
	while (i < BUFFER_SIZE && current_read[i] != '\0')
	{
		if (current_read[i] == '\n')
		{
			size = ft_strlen(current_read + i + 1);
			if (*remaining == 0)
				ft_strlcpy(*remaining, current_read + i, size);
			else
				ft_strlcat(*remaining, current_read + i, size);
			new_line = malloc(i + 1);
			if (!new_line)
				return(NULL);
			ft_strlcpy(new_line, current_read, size - i);
			return (new_line);
		}
		i++;
	}
	return (current_read);
}
char	*get_next_line(int fd)
{
	static char *remainig_data;
	char	*read_data;
	ssize_t	read_bytes;

	read_data = malloc(BUFFER_SIZE + 1);
	if (!read_data)
		return (NULL);
	read_bytes = read(fd, read_data, BUFFER_SIZE);
	if (read_bytes > 0)
	{
		read_data[BUFFER_SIZE + 1] = '\0';
		read_data = find_new_line(&remainig_data, read_data, fd);
	}
	else
	{
		free(read_data);
		return (NULL);
	}
	return (read_data);
}
