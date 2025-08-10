/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:10 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/10 12:54:05 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*c_str;
	size_t		i;

	if (!str || n == 0)
		return (NULL);
	c_str = (const char *)str;
	i = 0;
	while (c_str[i] != c && i < n)
		i++;
	if (c_str[i] != c && i == n)
		return (NULL);
	return ((char *)str + i);
}
