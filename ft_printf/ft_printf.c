/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:02:42 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/24 10:32:11 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_option(char **letter)
{}
static void	check_conversion(char letter, int *size, va_list args)
{
	if (letter == 'c')
		print_char(va_arg(args, char), size);
	if (letter == 's')
	if (letter == 'd')
	if (letter == 'i')
	if (letter == 'u')
	if (letter == 'x')
	if (letter == 'X')
	if (letter == 'p')
	if (letter == '%')
	{
		write(1, '%', 1);
		size++;
	}
}

int ft_printf(const char *string, ...)
{
	va_list	args;
	int	size;
	int	i;

	va_start(args, string);
	size = 0;
	i = 0;
	while (string != NULL)
	{
		if (string[i] == '%')
		{
			i++;
			while (!ft_isalpha(i))
			{
				handle_options(&string + i);
				i++;
			}
			check_conversion(string[i], &size, &args);
		}
		else
			write(1, string[i], 1);
		i++;
		size++;
	}
	return (size);
}
