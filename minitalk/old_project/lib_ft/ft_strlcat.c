/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:40:22 by dana              #+#    #+#             */
/*   Updated: 2024/09/20 20:17:52 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dsize;
	size_t	i;

	i = 0;
	dsize = ft_strlen(dst);
	if (dsize >= size)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && (dsize + i + 1) < size)
	{
		dst[dsize + i] = src[i];
		i++;
	}
	if (dsize < size)
		dst[dsize + i] = '\0';
	return (dsize + ft_strlen(src));
}

/*int main() {
    char str[100] = "there is no stars in the sky";
    const char *add = " its so dark!";
    int ss = ft_strlen(str);
    printf("%d\n", ss);
    printf("%ld\n", ft_strlcat(str, add, sizeof(add)));
    return 0;
}*/
