/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:35 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/17 13:25:15 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_remainder(char **remainder)
{
	free(*remainder);
	*remainder = NULL;
}

static char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)str + ft_strlen(str));
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

static void	update_remainder(char **remainder, char *buffer)
{
	char	*temp;

	if (!buffer)
		return ;
	if (!*remainder)
		*remainder = ft_strdup(buffer);
	else
	{
		temp = ft_strjoin(*remainder, buffer);
		if (!temp)
			return ;
		free(*remainder);
		*remainder = temp;
	}
}

static char	*extract_line(char **remainder)
{
	char	*newline_pos;
	char	*line;
	char	*temp;
	size_t	len;

	if (!*remainder)
		return (NULL);
	newline_pos = ft_strchr(*remainder, '\n');
	if (newline_pos)
	{
		len = newline_pos - *remainder + 1;
		line = ft_substr(*remainder, 0, len);
		temp = ft_strdup(*remainder + len);
		free(*remainder);
		*remainder = temp;
		return (line);
	}
	if (**remainder != '\0')
	{
		line = ft_strdup(*remainder);
		free_remainder(remainder);
		return (line);
	}
	free_remainder(remainder);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		update_remainder(&remainder, buffer);
	}
	free(buffer);
	line = extract_line(&remainder);
	return (line);
}
