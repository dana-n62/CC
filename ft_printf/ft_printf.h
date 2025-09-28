/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:02:18 by DaNa              #+#    #+#             */
/*   Updated: 2025/09/25 13:56:42 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

# include "./libft/libft.h"
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

void	print_char(unsigned int c, int *size);
void	print_str(char *str, int *size);
void	print_decimal(int number, int *size);
int ft_printf(const char *string, ...);
#endif
