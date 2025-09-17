/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:35 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/17 12:18:08 by DaNa             ###   ########.fr       */
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
	if (!*buffer || !buffer)
		return ;
	if (*remainder == NULL)
		*remainder = ft_strdup(*buffer);
	else
	{
		temp = ft_strjoin(*remainder, *buffer);
		if (!temp)
			return ;
		free(*remainder);
		*remainder = temp;
	}
}

static char	*find_a_line(int fd, char **rem, char **buff, ssize_t *read_bytes)
{
	char	*sub_string;
	char	*line;
	char	*temp;

	sub_string = NULL;
	while (*read_bytes >= 0)
	{
		sub_string = ft_strchr(*rem, '\n');
		if (sub_string != NULL)
		{
			line = ft_substr(*rem, 0, (sub_string - *rem));
			if (!line)
				break ;
			temp = *rem;
			*rem = ft_strdup(sub_string);
			free(temp);
			return (line);
		}
		*read_bytes = read(fd, *buff, BUFFER_SIZE);
		if (*read_bytes <= 0)
			break ;
		(*buff)[*read_bytes] = '\0';
		check_remainder(rem, buff);
	}
	return (NULL);
}

static int	start_search(char **line, int fd, char **remainder, char **buffer)
{
	ssize_t	read_bytes;

	read_bytes = read(fd, *buffer, BUFFER_SIZE);
	if (read_bytes < 0)
		return (read_bytes);
	(*buffer)[read_bytes] = '\0';
	check_remainder(remainder, buffer);
	*line = find_a_line(fd, remainder, buffer, &read_bytes);
	return (read_bytes);
}

char	*get_next_line(int fd)
{
	char		*found_line;
	char		*buffer;
	static char	*remainder;
	int			flag;

	found_line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	flag = start_search(&found_line, fd, &remainder, &buffer);
	if (found_line == NULL)
	{
		if (flag >= 0 || ft_strlen(remainder) > 0)
			flag = start_search(&found_line, fd, &remainder, &buffer);
		if (flag <= 0)
		{
			free(remainder);
			remainder = NULL;
		}
	}
	free(buffer);
	buffer = NULL;
	return (found_line);
}
