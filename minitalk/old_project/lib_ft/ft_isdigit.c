/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dana <dana@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 08:02:05 by dana              #+#    #+#             */
/*   Updated: 2024/09/30 09:25:29 by dana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <ctype.h> */
int	ft_isdigit(int str)
{
	if (str >= 48 && str <= 57)
		return (2048);
	else
		return (0);
}

/* int main()
{
	printf("%d\n", ft_isdigit(50));
	printf("%d\n", isdigit(50));
	return (0);
} */
//return 2048 as ctype.h
