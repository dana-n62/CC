/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:22:49 by dana              #+#    #+#             */
/*   Updated: 2024/09/25 13:16:10 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*new;
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(s1);
	new = 0;
	if (!s1 || !set)
		return (NULL);
	else
	{
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		new = (char *) malloc(j - i + 1);
		if (new)
			ft_strlcpy(new, &s1[i], j - i + 1);
	}
	return (new);
}
/*int	main(int argc, char **argv)
{
	if (argc > 1)
		printf("%s\n", ft_strtrim(argv[1], argv[2]));
	return (0);
}*/
