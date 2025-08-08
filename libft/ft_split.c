/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:44 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/08 13:43:30 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char *string, char c)
{
	int		word_flag;
	size_t	number_of_words;

	word_flag = 0;
	number_of_words = 0;
	while (string)
	{
		if (*string != c && word_flag == 0)
		{
			word_flag++;
			number_of_words++;
		}
		else if (*string == c && word_flag > 0)
			word_flag = 0;
		string++;
	}
	return (number_of_words);
}

static int	ft_word(char **all, const char *read, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*read)
	{
		while (*read == sep)
			read++;
		count = 0;
		while (read[count] != sep && read[count])
			count++;
		if (count > 0)
		{
			all[i] = ft_substr(read, 0, count);
			if (!all[i])
				return (0);
			i++;
		}
		read += count;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**strings_array;
	size_t	i;
	size_t	words_count;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	strings_array = malloc(sizeof(char *) * (words_count + 1));
	if (!strings_array)
		return (NULL);
	strings_array[words_count] = NULL;
	if (!ft_word(strings_array, s, c))
	{
		while (i < words_count)
			free(strings_array[i++]);
		free(strings_array);
		return (NULL);
	}
	return (strings_array);
}
