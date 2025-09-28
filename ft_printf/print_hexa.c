/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-28 09:31:26 by DaNa              #+#    #+#             */
/*   Updated: 2025-09-28 09:31:26 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_hexa(unsigned long number, char id, int *size)
{
    char    *letters;
    char    temp;

    letters = "abcdef";
    *size += 1;
    if ((number / 16)!= 0)
        print_hexa(number / 16, id, size);
    if ((number % 16) >= 10 || (number % 16) >= 15)
    {
        if (id == 'x')
            temp = letters[(number % 16) - 10];
        if (id == 'X')
            temp = ft_toupper(letters[(number % 16) - 10]);
    }
    else
        temp = (number % 16) + 48;
    write(1, &temp, 1);
}