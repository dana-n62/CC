/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:40 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/28 10:46:06 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	close(fd);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	i;
	size_t	ssize;

	i = 0;
	ssize = ft_strlen(src);
	if (dsize > 0)
	{
		while (i < (dsize - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ssize);
}
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	total;
	size_t	j;

	i = ft_strlen(dest);
	if (i >= size)
		return (size + ft_strlen(src));
	total = i + ft_strlen(src);
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (total);
}
size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}
