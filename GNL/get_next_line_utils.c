/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:40 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/17 11:38:29 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	ssize;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	ssize = ft_strlen(s);
	if (start >= ssize)
		return (ft_strdup(""));
	if (len > ssize - start)
		len = ssize - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		substr[i] = s[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	s1_length;
	size_t	s2_length;

	if (!s1 && !s2)
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
	size_t	i;

	str_len = ft_strlen(str);
	i = 0;
	duplicate = malloc(str_len + 1);
	if (!duplicate)
		return (NULL);
	while (i < str_len && str[i] != '\0')
	{
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	if (str == NULL || str[0] == '\0')
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

	if (dest == NULL)
		i = 0;
	else
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
