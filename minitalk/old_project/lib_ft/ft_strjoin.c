/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:39:28 by dana              #+#    #+#             */
/*   Updated: 2024/09/29 13:14:33 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		size1;
	int		size2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	join = (char *)malloc(size1 + size2 + 1);
	if (join == NULL)
		return (NULL);
	else
	{
		while (++i < size1)
			join[i] = s1[i];
		i = -1;
		while (++i < size2)
			join[i + size1] = s2[i];
	}
	join[i + size1] = '\0';
	return (join);
}
/*int	main(void)
{
	char	*prnt;

	prnt = ft_strjoin(NULL, NULL);
	printf("%s\n", prnt);
	
	free(prnt);
	return (0);
}*/
