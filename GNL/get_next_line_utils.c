/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:40 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/14 09:07:12 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	ssize;

	if (!s)
		return (NULL);
	ssize = ft_strlen(s);
	if (start >= ssize)
		return (ft_strdup(""));
	if (len > ssize - start)
		len = ssize - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	s1_length;
	size_t	s2_length;

	if (!s1 ||!s2)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	new_string = malloc(s1_length + s2_length + 1);
	if (!new_string)
		return (NULL);
	new_string[0] = '\0';
	ft_strlcat(new_string, s1, s1_length + 1);
	ft_strlcat(new_string + s1_length, s2, s2_length + 1);
	return (new_string);
}

char	*ft_strdup(const char *str)
{
	char	*duplicate;
	size_t	str_len;

	str_len = ft_strlen(str);
	duplicate = malloc((str_len + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	ft_strlcpy(duplicate, str, str_len + 1);
	return (duplicate);
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

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	if (str == NULL)
		return (size);
	while (str[size] != '\0')
		size++;
	return (size);
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

