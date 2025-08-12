/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:39 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/11 21:00:09 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//finds the given characters location and return the string starting there
char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	if (c == 0)
		return ((char *)str + ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			i++;
		else
			return ((char *)str + i);
	}
	return (NULL);
}
