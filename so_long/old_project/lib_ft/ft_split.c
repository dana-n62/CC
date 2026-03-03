/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <dana@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:05:13 by dana              #+#    #+#             */
/*   Updated: 2024/09/30 04:34:34 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const char *read, char sep)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (*read)
	{
		if (*read != sep && i == 0)
		{
			i++;
			count++;
		}
		else if (*read == sep && i > 0)
		{
			i = 0;
		}
		read++;
	}
	return (count);
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

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	size;
	char	**collection;

	if (!str)
		return (NULL);
	i = 0;
	size = ft_count(str, c);
	collection = (char **)malloc(((int)size + 1) * sizeof(char *));
	if (!collection)
		return (NULL);
	if (!ft_word(collection, str, c))
	{
		while (i < size)
			free(collection[i++]);
		free(collection);
		return (NULL);
	}
	collection[size] = NULL;
	return (collection);
}
/*int main() {
    const char *str = "Hello World This Is A Test";
    char sep = ' ';
    char **result = ft_split(str, sep);
    
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    for (int i = 0; result[i] != NULL; i++) {
        printf("Word %d: %s\n", i, result[i]);
        free(result[i]); // Free each allocated word
    }
    
    free(result); // Free the array of pointers
    return 0;
}*/
