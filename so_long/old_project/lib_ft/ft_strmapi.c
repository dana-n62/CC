/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:29:05 by dana              #+#    #+#             */
/*   Updated: 2024/09/29 13:21:27 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//first attempt at using pointer functions
/*char	test(unsigned int x, char y)
{
	int	*c = (int *) malloc(sizeof(int));

	c[0] = (int) x;
	free(c);
	return (y);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	string = (char *)malloc(ft_strlen(s) + 1);
	i = 0;
	if (string == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		string[i] = f(i, (char)s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
/*int	main(void)
{
	printf("%s\n", ft_strmapi("hello!", test));
	return (0);
}*/
