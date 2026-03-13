/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@students.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:30:02 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/03/03 07:11:17 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_number(char c, t_map **game, int x, int y)
{
	if (c == 'P')
	{
		(*game)->p_start.x = x;
		(*game)->p_start.y = y;
		return (1);
	}
	if (c == 'E')
	{
		(*game)->exit_loc.x = x;
		(*game)->exit_loc.y = y;
		return (2);
	}
	if (c == 'C')
		(*game)->to_collect++;
	else if (c != '0' && c != '1')
		return (-1);
	return (0);
}

int	valid_characters(t_map **game)
{
	int	x;
	int	y;
	int	count[2];
	int	check;

	x = -1;
	count[0] = 0;
	count[1] = 0;
	while (++x < (*game)->rows)
	{
		y = -1;
		while (++y < (*game)->cols)
		{
			check = check_number((*game)->map[x][y], game, x, y);
			if (check == 1)
				count[0]++;
			if (check == 2)
				count[1]++;
			if (check == -1)
				return (0);
		}
	}
	if (count[0] != 1 || count[1] != 1 || (*game)->to_collect < 1)
		return (0);
	return (1);
}

int	is_surround(t_map **g)
{
	int	i;

	i = 0;
	while (i < (*g)->cols)
	{
		if ((*g)->map[0][i] != '1' || (*g)->map[((*g)->rows) - 1][i] != '1')
		{
			ft_printf("Error\nIn surrounding walls (Rows)\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < (*g)->rows)
	{
		if ((*g)->map[i][0] != '1' || (*g)->map[i][((*g)->cols) - 1] != '1')
		{
			ft_printf("Error\nIn surrounding walls (Columns)\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_rectangular(t_map **game)
{
	int	length;
	int	i;

	i = 1;
	while ((*game)->map[i] != NULL)
	{
		length = ft_strlen((*game)->map[i]);
		if (length != (*game)->cols)
		{
			ft_printf("Error\nNot rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_valid(t_map **game)
{
	if (is_rectangular(game) != 1)
		return (0);
	if (is_surround(game) != 1)
		return (0);
	if (valid_characters(game) != 1)
	{
		ft_printf("Error\nInvalid character used\n");
		return (0);
	}
	if (validate_path(game) != 1)
	{
		ft_printf("Error\nNo valid path\n");
		return (0);
	}
	return (1);
}
