/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:28:32 by dana              #+#    #+#             */
/*   Updated: 2024/09/19 04:26:57 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	si;

	i = 0;
	si = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + si);
	while (i < si && *s)
	{
		if (s[i] != (char)c)
			i++;
		else
			return ((char *)s + i);
	}
	return (NULL);
}
