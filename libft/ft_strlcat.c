/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:55 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/10 13:16:53 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	total;
	size_t	j;

	i = ft_strlen(dest);
	if (i >= size)
		return (size + ft_strlen(src));
	total = i + size;
	if ((int)size > 0)
	{
		j = 0;
		while (i < (size - 1) && src[j] != '\0')
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
	}
	return (total);
}
