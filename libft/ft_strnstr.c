/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:07 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/08 13:50:15 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay_str, const char *needle_str, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!hay_str || n == 0)
		return (NULL);
	if (needle_str[0] == '\0')
		return ((char *)hay_str);
	while (hay_str[i] != '\0' && i < n)
	{
		j = 0;
		if (hay_str[i] == needle_str[j])
		{
			while (hay_str[i] == needle_str[j] && needle_str && i < n)
			{
				i++;
				j++;
			}
			if (needle_str[j] == '\0')
				return ((char *)hay_str + (i - j));
		}
		if (n - i < ft_strlen(needle_str))
			break ;
		else
			i++;
	}
	return (NULL);
}
