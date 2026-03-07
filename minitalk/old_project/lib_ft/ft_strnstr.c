/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:58:13 by dana              #+#    #+#             */
/*   Updated: 2024/09/26 13:38:10 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	int			count;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		count = 0;
		while (little[count] && big[i + count] == little[count])
		{
			if ((i + count) >= len)
				break ;
			count++;
		}
		if (little[count] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	hay[] = "aaxx";
	const char	needle[] = "xx";
	char	*location = ft_strnstr(hay, needle, 3);
	printf("%s \n", location);
	//printf("%s \n", strnstr(hay, needle, 2));
	return (0);
}*/
