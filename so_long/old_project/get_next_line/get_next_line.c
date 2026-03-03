/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <dana@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:38:50 by dana              #+#    #+#             */
/*   Updated: 2025/02/04 13:21:13 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*core_of_gnl(char **remainder)
{
	char	*new_line;
	char	*temp;
	size_t	length;

	new_line = NULL;
	length = 0;
	if (ft_strchr(*remainder, '\n'))
	{
		length = (ft_strchr(*remainder, '\n')) - *remainder + 1;
		new_line = ft_substr_gnl(*remainder, 0, length);
		temp = ft_substr_gnl(*remainder, length, (ft_strlen(*remainder)) - length);
		if (temp)
		{
			free(*remainder);
			*remainder = temp;
		}
	}
	if (!new_line && ft_strlen(*remainder))
	{
		new_line = ft_substr_gnl(*remainder, 0, ft_strlen(*remainder));
		free(*remainder);
		*remainder = NULL;
	}
	return (new_line);
}

ssize_t	find_line(int fd, char *buffer, char **remainder)
{
	ssize_t		file_read;
	char		*temp;

	file_read = read(fd, buffer, BUFFER_SIZE);
	if (!(*remainder))
	{
		*remainder = (char *)malloc(sizeof(char));
		if (*remainder)
			(*remainder)[0] = '\0';
	}
	if (*remainder && file_read >= 0)
	{
		buffer[file_read] = '\0';
		temp = ft_strjoin_gnl(*remainder, buffer);
		if (!temp)
			return (-1);
		free(*remainder);
		*remainder = temp;
	}
	else
		return (-1);
	return (file_read);
}

ssize_t	reading(int fd, char **remainder)
{
	char		*buffer;
	ssize_t		file_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	file_read = find_line(fd, buffer, remainder);
	while (file_read > 0 && !(ft_strchr(*remainder, '\n')))
		file_read = find_line(fd, buffer, remainder);
	free(buffer);
	return (file_read);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*remainder;
	ssize_t			file_read;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file_read = reading(fd, &remainder);
	if (file_read < 0 || !remainder || remainder[0] == '\0')
	{
		free(remainder);
		remainder = NULL;
		return (line);
	}
	line = core_of_gnl(&remainder);
	if (!line)
	{
		free(remainder);
		remainder = NULL;
	}
	return (line);
}
