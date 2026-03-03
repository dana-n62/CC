/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:42:15 by Dana Nour         #+#    #+#             */
/*   Updated: 2026/02/03 13:37:17 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
}	t_data;

int	esc_win(int	key_value, t_data *param)
{
	if (key_value == XK_Escape)
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	return (0);
}

int	mouse_win(t_data *param)
{
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	return (0);
}

int	do_nothing()
{
	return (0);
}

int	main(void)
{
	t_data	test;

	test.mlx_ptr = mlx_init();
	if (!test.mlx_ptr)
		exit(0);
	test.x = 400;
	test.y = 600;
	test.win_ptr = mlx_new_window(test.mlx_ptr, test.x, test.y, "test test");
	if(!test.win_ptr)
	{
		free(test.win_ptr);
		exit(0);
	}

	mlx_key_hook(test.win_ptr, &esc_win, &test);
	mlx_hook(test.win_ptr, 17, 0,&mouse_win, &test); //this event only interacts when (x) is pressed
	if (read_map_file("test.ber") < 0)
	{
		ft_printf("file not valid\n");
		mlx_destroy_display(test.mlx_ptr);
		free(test.win_ptr);
		free(test.mlx_ptr);
		exit(0);
	}
	mlx_loop_hook(test.mlx_ptr, &do_nothing, NULL);
	mlx_loop(test.mlx_ptr);
	mlx_destroy_display(test.mlx_ptr);
	free(test.mlx_ptr);
	return (0);
}
