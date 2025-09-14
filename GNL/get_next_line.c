/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:35 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/14 09:05:35 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static void	check_remainder(char **remainder, char *buffer)
{
	char	*temp;

	temp = NULL;
	if (*remainder)
	{
		temp = ft_strjoin(*remainder, buffer);
		*remainder = ft_strdup(temp);
		free(temp);
	}
	else
		*remainder = ft_strdup(buffer);
}
static char	*find_a_line(int fd, char **remainder, char **buffer, ssize_t *read_bytes)
{
	char	*sub_string;
	char	*line;
	int	len;

	sub_string = ft_strchr(*remainder, '\n');
	if (sub_string)
	{
		len = sub_string - *remainder;
		line = ft_substr(*remainder, 0, len + 1);
		if (!line)
		{
			free(*remainder);
			return (NULL);
		}
		*remainder = ft_strdup(sub_string);
		*read_bytes = read(fd, *buffer, BUFFER_SIZE);
		if (!*read_bytes)

		return (line);
	}
	free(*buffer);
	return (NULL);
}
static char	*start_the_search(int fd, char **remainder)
{
	ssize_t	read_bytes;
	char	*buffer;
	char	*line;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[read_bytes] = '\0';
	check_remainder(remainder, buffer); //second check the box
	if (!*remainder)
	{
		free(buffer);
		return (NULL);
	}
	line = find_a_line(fd, remainder, &buffer, &read_bytes); // third try to find a line
	while (line || read_bytes > 0)
		find_a_line(fd, remainder, &buffer, &read_bytes);
	return (line);
}
char	*get_next_line(int fd)
{
	char	*found_line;
	static char	*remainder;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	found_line = start_the_search(fd, &remainder); //first read the file
	if (found_line == NULL)
	{
		if (remainder)
		{
			found_line = ft_strdup(remainder);
			free(remainder);
		}
		else
			return (NULL);
	}
	return (found_line);
}
