/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:27 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/06 11:08:17 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//more reialble than memcpy but slower
//no NULL checks in neither -- non standard
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*c_dest;
	const char	*c_src;
	int			i;

	c_dest = (char *)dest;
	c_src = (const char *)src;
	i = 0;
	if (c_dest + n > c_src)
	{
		while ((int)n >= 0)
		{
			c_dest[n] = c_src[n];
			n--;
		}
	}
	else
	{
		while (i < (int)n)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	return (dest);
}
