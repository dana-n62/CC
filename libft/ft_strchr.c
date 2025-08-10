/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:39 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/10 12:56:17 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//finds the given characters location and return the string starting there
char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != c && str)
		str++;
	return ((char *)str);
}
