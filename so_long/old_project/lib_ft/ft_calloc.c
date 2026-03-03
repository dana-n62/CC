/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <dana@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:17:46 by dana              #+#    #+#             */
/*   Updated: 2024/09/30 09:40:26 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stddef.h>
#include <stdlib.h> */
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*temp;
	size_t	total;

	if (n == 0 && size == 0)
	{
		n = 1;
		size = 1;
	}
	total = n * size;
	temp = (char *)malloc(total);
	if (temp == NULL)
		return (NULL);
	else
	{
		ft_bzero(temp, n * size);
		return ((void *)temp);
	}
}
/* int	main()
{
	char *s = (char *) ft_calloc(0, 0);
	return (0);
} */
