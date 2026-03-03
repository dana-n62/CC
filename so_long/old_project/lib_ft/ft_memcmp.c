/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <dana@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 04:29:23 by dana              #+#    #+#             */
/*   Updated: 2024/09/30 10:43:50 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <string.h> */
int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	const unsigned char	*val1;
	const unsigned char	*val2;

	val1 = (const unsigned char *)pointer1;
	val2 = (const unsigned char *)pointer2;
	if (size == 0)
		return (0);
	while ((size - 1) > 0 && (*val1 == *val2))
	{
		val1++;
		val2++;
		size--;
	}
	return (*val1 - *val2);
}
/* int	main(void)
{
	char *s1 = "star";
	char *s2 = "stra";
	printf("%d\n", ft_memcmp(s1, s2, 7));
	printf("%d\n", memcmp(s1, s2, 7));
	return (0);
} */
