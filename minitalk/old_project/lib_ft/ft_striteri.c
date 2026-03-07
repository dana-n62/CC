/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <dana@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:35:44 by dana              #+#    #+#             */
/*   Updated: 2024/09/30 10:57:09 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//passes char to function pointer for manipulation
/*void	print(unsigned int x, char *y)
{
	printf("%c\n", y[x]);
}*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*int	main(void)
{
	void (*ft)(unsigned int, char*);
	char	*s = "Hello World";
	unsigned int x = 5;
	ft = print;
	ft_striteri(s, (*ft(x, s)));
	return (0);
}*/
