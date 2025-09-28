/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:50:09 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/25 16:03:45 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_decimal(double number, int *size)
{
	char	*string_number;
	int	i;

	string_number = ft_itoa(number);
	i = 0;
	while (string_number[i] != '\0')
	{
		write(1, &string_number[i], 1);
		i++;
	}
	*size += i;
}
