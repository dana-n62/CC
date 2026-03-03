/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:59:50 by dana              #+#    #+#             */
/*   Updated: 2024/09/20 19:54:19 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + i);
	while (i >= 0 && *s)
	{
		if ((char)c == 0)
			return ((char *)s + i);
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*int	main(void)
{
	char	*s = "lost and found";
	char	find = 'n';

	printf("%c found at location %s\n", find, ft_strrchr(s, find));
	return (0);
}*/
