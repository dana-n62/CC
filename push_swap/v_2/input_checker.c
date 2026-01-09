/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dana Nour <dna2@student.42amman.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:21:39 by Dana Nour         #+#    #+#             */
/*   Updated: 2025/12/14 09:10:18 by Dana Nour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//this functio is meant to check the validty of the input:
//1-all integers, 2- within INT_MAX & INT_MIN, 3- no repeatition
//if content is validated then a list is returned to main function
void	create_array(int **data, char *argv, int size)
{
	int	i;

	i = 0;
	data = malloc(sizeof(int) * size);
	if (!data)
		return ;
	while (i++ < size)
	{
		data[i] = ft_atoi(argv[i]);
		if (data[i] > INT_MAX || data[i] < INT_MIN)
		{
			free(data);
			ft_printf("Error\n");
			exit (1);
		}
	}
}
void	check_duplicate(int **data, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j > size)
		{
			if (data[i] == data[j])
			{
				free(data);
				ft_printf("Error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
}

int	*input_checker(char *argv)
{
	int	i;
	int	data;

	i = 0;
	while (argv[i] != '\0')
	{
		if(!ft_isdigit(argv[i++]))
		{
			ft_printf("Error\n");
			exit (1);
		}
	}
	data = ft_atoi(argv);
	if (data > INT_MAX || data < INT_MIN)
	{
		ft_printf("Error\n");
		exit (1);
	}
	/* create_array(&data, argv, size);
	check_duplicate(&data, size); */
	return (data);// when exiting we should check for any created nodes and free everything
}
