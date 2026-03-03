/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:08:43 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/02/03 13:46:26 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "./minilibx-linux/mlx.h"
# include "./GNL/get_next_line.h"
# include "./libft/libft.h"
# include <stdlib.h>
/* # include <X11/X.h> */
# include <X11/keysym.h>

int	read_map_file(char *file_name);

#endif
