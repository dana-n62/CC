/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:07 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/06 11:11:40 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay_str, const char *needle_str, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	needle_size;

	i = 0;
	j = 0;
	needle_size = ft_strlen(needle_str);
	if (!hay_str || n == 0)
		return (NULL);
	if (needle_str[0] == '\0')
		return ((char *)hay_str);
	while (hay_str[i] != '\0' && i < n)
	{
		j = 0;
		if (hay_str[i] == needle_str[j])
		{
			while ((hay_str[i] == needle_str[j]) && (needle_str[j] != '\0') && i < n)
			{
				i++;
				j++;
			}
			if (needle_str[j] == '\0')
				return ((char *)hay_str + (i - j));
		}
		if (n - i < needle_size)
			break ;
		else
			i++;
	}
	return (NULL);
}
