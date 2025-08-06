/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:15 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/06 11:05:15 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*c_str1;
	unsigned char	*c_str2;

	i = 0;
	c_str1 = (unsigned char *)str1;
	c_str2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (i <= n)
	{
		if (c_str1[i] < c_str2[i] || c_str1[i] > c_str2[i])
			break ;
		i++;
	}
	return (c_str1[i] - c_str2[i]);
}
