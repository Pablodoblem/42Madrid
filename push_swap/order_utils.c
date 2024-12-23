/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:25:41 by pamarti2          #+#    #+#             */
/*   Updated: 2024/12/22 20:47:03 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_stack_order(float **arr_a, int argc, int flag)
{
	int	i;

	i = 0;
	if (flag == 1) // para FH
	{
		while ((*arr_a)[i] - (*arr_a)[i + 1] < 0)
			i++;
		if (i == ((argc - 1) / 2))
			return (1);
	}
	else if (flag == 2) //para SH
	{
		while ((*arr_a)[i] - (*arr_a)[i + 1] > 0)
			i++;
		if (i == ((argc - 1) - ((argc - 1) / 2)))
			return (1);
	}
	else if (flag == 3)
	{
		printf("ARGC: %d\n", argc);
		while ((i + 1) < argc - 1 && (*arr_a)[i] - (*arr_a)[i + 1] < 0) //segunda parte de la condicional añadida como posible fix
		{
			printf("(*arr_a)[i] : %.1f\n", (*arr_a)[i]);
			printf("(*arr_a)[i + 1] : %.1f\n", (*arr_a)[i + 1]);
			printf("\n ----------------------- \n");
			i++;
		}
		if (i == argc - 2)
			return (1);
	}
	return (0);
}

int good_order(float **arr, float **arr_b, int argc)
{
	float	*aux;
    int		i;
	int		y;
	int		counter;

	counter = 0;
	i = 0;
	y = 0;
	aux = ft_floatcalloc((argc - 1), sizeof(float));
	while (i < argc - 1)
	{
		aux[i] = (*arr)[i];
		i++;
	}
	printf("\n");
	i = 0;
	while (y < argc - 1)
	{
		counter = 0;
		i = 0;
		while (i < argc - 2)
		{
			if (aux[i] > aux[i + 1]) // Si no está en orden ascendente
				break ;
			else
				counter++;
			i++;
		}
		rx_to_stack(&aux, arr_b, 'a', argc);
		if (counter == argc - 2)
		{
			printf("ORDENADO\n");
			return (y);
		}
		y++;
	}
	printf("NO ORDENADO\n");
	free (aux);
	return (-1);
}

int	order_stack_arr_c(float **arr_b, float **arr_c, int moves_to_deposit, int argc)
{
	int		i;
	int		aux_moves;
	// float	aux_float;
	int		flag;
	int		flag2;
	int		instructions;
	int		aux_max_num;

	aux_max_num = 0;
	instructions = 0;
	i = 0;
	flag = 0;
	flag2 = 0;
	while (i < argc - 1 && (*arr_c)[i] != 0.5) //Trata de encontrar valores = move_to_deposit
	{
		if ((*arr_c)[i] == moves_to_deposit)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	//instructions = i; 
	i = 0;
	while (i < argc - 1 && flag == 0) //En caso de no haber encontrado el mismo numero moves_to_deposit se busca el número más alto
	{
		if ((*arr_c)[0] == 0.5) //si arr_b está vacío break
			break ;
		if ((*arr_c)[i] >= aux_max_num)
		{
			flag2 = 1;
			aux_max_num = (*arr_c)[i];
		}
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		if ((*arr_c)[i] == aux_max_num)
		{
			// while ((*arr_c)[i + 1] == aux_max_num)
			// 	i++;
			break ;
		}
		i++;
	}

	printf("Moves to deposit: %d\n", moves_to_deposit);
	aux_moves = moves_to_deposit;
	while (aux_moves > 0 && flag == 1)
	{
		rx_to_stack(arr_c, arr_b, 'a', argc);
		rx_to_stack(arr_c, arr_b, 'b', argc);
		aux_moves--;
		instructions++;
	}
	while (i > 0 && flag2 == 1 && flag == 0)
	{
		rx_to_stack(arr_c, arr_b, 'a', argc);
		rx_to_stack(arr_c, arr_b, 'b', argc);
		instructions++;
		i--;
	}
	// if (flag2 == 1)
	// {
	// 	while ((*arr_b)[0] < )
	// }
	return  (instructions);
}
