/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:38:28 by dana              #+#    #+#             */
/*   Updated: 2024/09/19 11:05:46 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 != '\0' && (*s1 == *s2) && i < n)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*int	main(void)
{
	const char	*st1 = "banana";
	const char	*st2 = "bpple";

	printf("%d\n", ft_strcmp(st1, st2));
	printf("%d\n", strcmp(st1, st2));
	return (0);
}*/
