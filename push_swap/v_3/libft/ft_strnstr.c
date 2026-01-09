/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:47:07 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/09 11:12:09 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	count;

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
/* int	main(void)
{
	const char	hay[] = "aaxx";
	const char	needle[] = "xx";
	char	*location = ft_strnstr(hay, needle, 4);
	printf("%s \n", location);
	//printf("%s \n", strnstr(hay, needle, 2));
	return (0);
} */
