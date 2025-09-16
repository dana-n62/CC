/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:35 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/15 12:16:13 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	if ((char)c == 0)
		return ((char *)str + ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i + 1);
		i++;
	}
	return (NULL);
}

static void	check_remainder(char **remainder, char **buffer)
{
	char	*temp;

	temp = NULL;
	if (*remainder)
	{
		temp = ft_strjoin(*remainder, *buffer);
		free(*remainder);
		*remainder = ft_strdup(temp);
		free(temp);
	}
	else
		*remainder = ft_strdup(*buffer);
}

static char	*search(int fd, char **remainder, char **buffer, ssize_t read_bytes)
{
	char	*sub_string;
	char	*line;
	char	*temp;

	while (read_bytes > 0)
	{
		sub_string = ft_strchr(*remainder, '\n');
		if (sub_string != NULL)
		{
			line = ft_substr(*remainder, 0, (sub_string - *remainder));
			if (!line)
				break ;
			temp = *remainder;
			*remainder = ft_strdup(sub_string);
			free(temp);
			return (line);
		}
		read_bytes = read(fd, *buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		(*buffer)[read_bytes] = '\0';
		check_remainder(&remainder[fd], buffer);
	}
	return (NULL);
}

static char	*start_the_search(int fd, char **remainder, char **buffer)
{
	ssize_t	read_bytes;
	char	*line;

	read_bytes = read(fd, *buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
		return (NULL);
	(*buffer)[read_bytes] = '\0';
	check_remainder(&remainder[fd], buffer);
	if (*remainder == NULL)
		return (NULL);
	line = search(fd, &remainder[fd], buffer, read_bytes);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*found_line;
	char		*buffer;
	static char	*remainder[2000];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	found_line = start_the_search(fd, &remainder[fd], &buffer);
	if (found_line == NULL)
	{
		if (ft_strlen(remainder[fd]) != 0)
			found_line = ft_strdup(remainder[fd]);
		free(remainder[fd]);
		remainder[fd] = NULL;
	}
	free(buffer);
	buffer = NULL;
	return (found_line);
}
