/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <dana@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:05:03 by dana              #+#    #+#             */
/*   Updated: 2024/09/30 11:20:24 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  memory area pointed to by s for the first instance of value
#include <stdio.h>
#include <string.h> */
#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*temp;
	unsigned char	temp_v;
	size_t			i;

	i = 0;
	temp = (unsigned char *)ptr;
	temp_v = (unsigned char)value;
	while (i < num)
	{
		if (temp[i] == temp_v)
		{
			return ((void *)temp + i);
		}
		i++;
	}
	return (NULL);
}
/* int	main(void)
{
	char	*f,*k;
	char	p[] = "hello my name is dana";

	k = ft_memchr(p, 0, 0);
	f = memchr(p, 0, 0);
	printf("%p\n", k);
	printf("%p\n", f);
	return (0);
}
 */
