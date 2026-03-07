/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:08:39 by dana              #+#    #+#             */
/*   Updated: 2024/09/16 08:07:13 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*rep;
	int		size;

	size = ft_strlen(src) + 1;
	rep = malloc(size);
	if (!rep)
		return (NULL);
	return (ft_strcpy(rep, src));
}

/*int	main(void)
{
	char	name[] = "dana";
	printf("%s\n", ft_strdup(name));
	return (0);
}*/
