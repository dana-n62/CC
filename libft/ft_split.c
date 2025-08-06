/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:44 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/06 10:46:45 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "libft.h"

// static int	count_strings(const char *s, char c)
// {
// 	int	counter;
// 	int	i;
// // printf("here");
// 	counter = 1;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if ((s[i] == c) && (s[i] != s[i + 1]) && (s[i + 1] != '\0'))
// 		{
// 			// i++;
// 			while (s[i] && s[i] != c)
// 				i++;
// 			counter++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (counter);
// }

static int	count_strings(const char *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while(s[i] != '\0' && s[i] != c)
			i++;
		if(s[i] != '\0' && s[i] == c && s[i + 1] != c)
		{
			counter++;
			i++;
		}
	}
	return (counter + 1);
}
static size_t size_of_slot(const char *s, char c)
{
	size_t	size;

	size = 0;
	while (*s != c && *s != '\0')
	{
		size++;
		s++;
	}
	return (size);
}

static	int splitting_function(char **split, const char **s, char c)
{
	size_t	size;
	size_t	size_s;

	size_s = ft_strlen(*s);
	size = size_of_slot(*s, c);
	*split = malloc(sizeof(char) * (size + 1));
	if (!*split)
	{
		free(*split);
		return(0);
	}
	ft_strlcpy(*split, *s, size + 1);
	if (ft_strlen(*s + size) > size_s)
		*s += size_s;
	else
		*s += size;
	return (1);
}

static char *clean_heap(char ***array, int i)
{
	while (i >= 0)
		free(*array[i]);
	free(**array);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	int	number_of_strings;
	int	i;
		printf("here\n");
	if (!s)
		return (NULL);
	number_of_strings = count_strings(s, c);
	split = malloc(sizeof(char *) * (number_of_strings + 1));
	if (!split)
		return (NULL);
 	while (i < number_of_strings)
	{
		while (s)
		{
			if (*s == c && *s != *(s + 1))
			{
				if (!splitting_function(&split[i], &s, c))
					{
						clean_heap(&split, i);
						break;
					}
			}
			else
				s++;
		}
		i++;
		split[i] = NULL;
	}
	return (split);
}
// int main(void)
// {
// 	int count = count_strings("hello dana here", '.');
// 	printf("%d\n", count);
// 	return(0);
// }
 */
