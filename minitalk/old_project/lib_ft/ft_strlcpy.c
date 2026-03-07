/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:07:27 by dana              #+#    #+#             */
/*   Updated: 2024/09/02 12:33:23 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size == 0)
	{
		while (src[count])
			count++;
		return (count);
	}
	while (src[count] != '\0' && count < size - 1)
	{
		dst[count] = src[count];
		count++;
	}
	if (count < size)
		dst[count] = '\0';
	while (src[count] != '\0')
		count++;
	return (count);
}
