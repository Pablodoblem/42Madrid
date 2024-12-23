/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:29:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/12/23 18:56:35 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	check_arg_format(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_isdigitmod(argv[i]) == 1)
			return (1);
		if (ft_strlen(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	find_extremes(float **arr_d, float **originalarr, int argc)
{
	int	i;
	float	aux;

	i = 0;
	aux = 0;
	while (i < argc - 1)
	{
		if ((*originalarr)[i] > aux)
			aux = (*originalarr)[i];
		i++;
	}
	(*arr_d)[1] = aux;
	i = 0;
	while (i < argc - 1)
	{
		if ((*originalarr)[i] < aux)
			aux = (*originalarr)[i];
		i++;
	}
	(*arr_d)[0] = aux;
	i = 0;
	while (i < argc - 1)
	{
		if ((*originalarr)[i] == (*arr_d)[0])
			(*originalarr)[i] += 0.5;
		i++;
	}
}

int	manage_stackb_n_tracker(float **originalarr, float **arr_b, int argc)
{
	int		num;

	num = 0;
	while(num < argc - 1)
	{
		if ((*arr_b)[num] == 0.5)
			break ;
		num++;
	}
	if ((*arr_b)[0] == 0.5)
		return (0);
	else if (num == 1) 
	{
		if ((*originalarr)[0] > (*arr_b)[0])
			return (-1);
		else
			return (1);
	}
	return (0);
}

void	last_chance(float **originalarr, float **sortedarr_a, float **arr_b, int argc)
{
	float	*arr_c;
	float	*arr_d;
	float	*copy;
	int		i;
	int		moves_to_good_order;	
	int		moves_to_deposit;
	int		instructions;
	int		zero;
	int		y = 0; //quitar
	int		x; //quitar
	int		j;
	int		flag;
	int		zero_check;

	flag = 0;
	j = 0;
	i = 0;
	instructions = 0;
	printf("ARR_A ORIGINAL SIN PROCESAR:\n");
	print_stacks(*originalarr, *arr_b, argc);
	arr_c = ft_floatcalloc((argc - 1), sizeof(float));
	copy = ft_floatcalloc((argc - 1), sizeof(float));
	arr_d = ft_floatcalloc(2, sizeof(float));
	find_extremes(&arr_d, originalarr, argc);
	i = 0;
	while (i < argc - 1)
	{
		copy[i] = (*originalarr)[i];
		i++;
	}
	i = 0;
///-------------------------------------------------///
	while (i < 2)
	{
		printf("%.1f\n", arr_d[i]);
		i++;
	}
///-------------------------------------------------///
	i = 0;
	printf("STACKS con blocked nums: \n");
	printf("ARGC: %d\n", argc);
	block_ordered_num(originalarr, arr_b, sortedarr_a, argc, arr_d[0]);
	print_stacks(*originalarr, *arr_b, argc);
	while (1)
	{
		printf("COPIA ORIGINAL:\n");
		i = 0;
		while(i < argc - 1)
		{
			printf("%.1f\n", copy[i]);
			i++;
		}
		if (good_order(originalarr, arr_b, argc) != -1)
			break ;
		printf("arr:d[0]: %.1f\n", arr_d[0]);
		printf("arr:d[0]: %.1f\n", arr_d[1]);

		printf("Flag: %d\n", flag);
		zero = check_zero(&arr_c, arr_b, argc, 1);
		while (zero != -1) // --------------- FUNCIÓN DE DESCARGA DE NÚEROS EN STACK A
		{
			printf("\033[4;31mEntrando en función de descarga.\033[0m\n");
			printf("zero: %d\n", zero);
			if (zero == 0)
			{
				px_to_stack(originalarr, arr_b, 'a', argc);
				move_the_row(&arr_c, argc, 2);
				(*originalarr)[0] += 0.5;
				instructions++;
			}
			else if (zero > 0)
			{
				while (zero > 0)
				{
					printf("rotate stack b\n");
					rx_to_stack(originalarr, arr_b, 'b', argc);
					printf("rotate stack c\n");
					rx_to_stack(&arr_c, arr_b, 'a', argc);
					instructions++;
					zero--;
				}
				move_the_row(&arr_c, argc, 2);
				px_to_stack(originalarr, arr_b, 'a', argc);
				(*originalarr)[0] += 0.5; //REVISIÓN!
			}
			printf("rotate stack a\n");
			rx_to_stack(originalarr, arr_b, 'a', argc);
			printf("decreasing numbers stack c\n");
			instructions++;
			print_stacks(*originalarr, *arr_b, argc);
			zero = check_zero(&arr_c, arr_b, argc, 1);
			printf("zero: %d\n", zero);
			printf("arr_c:\n");
			x = 0;
			while (x < argc - 1)
			{
				printf("%.1f\n", arr_c[x]);
				x++;
			}
		}

		printf("(*originalarr)[0] = %.1f\n", (*originalarr)[0]);
		printf("Valor de y: %d\n", y);
		if ((*originalarr)[0] == arr_d[0]) // ------------------- ESTE ES EL CASO DE LOWEST NUMBER
		{
			printf("Hubo (*originalarr)[0] == arr_d[0].\n");
			(*originalarr)[0] += 0.5;
			rx_to_stack(originalarr, arr_b, 'a', argc);
			instructions++;
			printf("Originalarr:\n");
			print_stacks(*originalarr, *arr_b, argc);
			decrease_numbers(&arr_c, argc, 1, 0);
			flag = 1;
///-------------------------------------------------///
			printf("arr_c:\n");
			x = 0;
			while (x < argc - 1)
			{
				printf("%.1f\n", arr_c[x]);
				x++;
			}
///-------------------------------------------------///
		}
		else if (!(((*originalarr)[0]) - (int)(*originalarr)[0] >= 0.4999) && ((*originalarr)[0] - (int)(*originalarr)[0] <= 0.5001))
		{
			if (!((*originalarr)[0] == arr_d[1] && (*originalarr)[1] == arr_d[0]))
			{
				if ((*originalarr)[0] == arr_d[1])
				{
					printf("Entrando\n");
					moves_to_deposit = check_destination((*originalarr)[0], sortedarr_a, originalarr, argc, arr_b, arr_d[0], 1, flag) + 1;	
				}
				else
				{
					moves_to_deposit = check_destination((*originalarr)[0], sortedarr_a, originalarr, argc, arr_b, arr_d[0], 2, flag);
				}
				printf("moves_to_deposit: %d\n", moves_to_deposit);
				zero_check = find_zero(&arr_c, argc, 1);
				instructions += order_stack_arr_c(arr_b, &arr_c, moves_to_deposit, argc);
				 
				if (zero_check != -1)
					i = ((j = zero_check), (j - 1));
				while (j >= 0 || i >= 0)
					arr_c[j--] = arr_c[i--];
				if (moves_to_deposit < 0)
				{
					printf("moves_to_deposit <= 0\n");
					moves_to_deposit *= -1;
					printf("arr_c[0]: %.1f\n", arr_c[0]);
					printf("arr_c[moves_to_deposit + 1]: %.1f\n", arr_c[moves_to_deposit + 1]);
					arr_c[0] = arr_c[moves_to_deposit + 1];
					printf("arr_c[0]: %.1f\n", arr_c[0]);
				}
				else if (moves_to_deposit == 0 && (*originalarr)[0] != arr_d[1]) //antes solo era if y lo siguiente else solo
					arr_c[0] = arr_c[1];
				else
				{
					arr_c[0] = moves_to_deposit;
				}
				px_to_stack(originalarr, arr_b, 'b', argc);
				if ((*arr_b)[1] != 0.5)
				{
					if ((*arr_b)[0] > (*arr_b)[1])
					{
						wx_to_stack(originalarr, arr_b, 'b');
						wx_to_stack(originalarr, &arr_c, 'b');
					}
				}
				// if ((*arr_b)[0] > (*arr_b)[1] && (*arr_b)[1] != 0.5)
				// {
				// 	if ((arr_b)[2] != 0.5 && (*arr_b)[0])
				// 	{

				// 	}
				// 	wx_to_stack(originalarr, arr_b, 'b');
				// 	instructions++;
				// }
				// else if ((*arr_b)[0] > (*arr_b)[1] && (*arr_b)[2] != 0.5)
				// {

				// }
				printf("MANAGER: %d\n", manage_stackb_n_tracker(originalarr, arr_b, argc));
				instructions++;
				printf("Originalarr:\n");
				print_stacks(*originalarr, *arr_b, argc);
				decrease_numbers(&arr_c, argc, 1, 0);
				
	///-------------------------------------------------///
				printf("arr_c tras decrease:\n");
				x = 0;
				while (x < argc - 1)
				{
					printf("%.1f\n", arr_c[x]);
					x++;
				}
			}
			else
			{
				(*originalarr)[0] += 0.5;
			}
///-------------------------------------------------///
		}
		else if ((((*originalarr)[0]) - (int)(*originalarr)[0] >= 0.4999) && ((*originalarr)[0] - (int)(*originalarr)[0] <= 0.5001))
		{
			printf("Hubo número con 0.5\n");
			rx_to_stack(originalarr, arr_b, 'a', argc);
			instructions++;
			printf("Originalarr:\n");
			print_stacks(*originalarr, *arr_b, argc);
			decrease_numbers(&arr_c, argc, 1, 0);
			x = 0;
			while (x < argc - 1) //print de arr_c
			{
				printf("%.1f\n", arr_c[x]);
				x++;
			}
			//}
		}
		y++;
	}
	printf("Moves till good order: %d\n", moves_to_good_order = good_order(originalarr, arr_b, argc));
	while (moves_to_good_order > 0)
	{
		rx_to_stack(originalarr, arr_b, 'a', argc);
		moves_to_good_order--;
		instructions++;
	}
	printf("Stacks Ordenados:\n");
	print_stacks(*originalarr, *arr_b, argc);
	printf("Número de movimientos realizados: %d\n", instructions);
	free (arr_c);
	free (arr_d);
}

int main(int argc, char **argv) //hacer check para valores numéricos int repetidos en argumentos
{
	int		i;
	//char	*operations[] = {"pb", "pb", "sa", "pa", "pa", "sa"};
	float		*arr_a;
	float		*arr_b;
	int			vueltas = 1;
	int			ops;
	float		*originalarr;

	ops = 0;
	i = 0;
	if (argc < 2)
	{
		printf("No arguments provided\n");
		return (1);
	}
	if (check_arg_format(argc, argv) == 1)
	{
		printf("Invalid argument format\n");
		return (1);
	}
	arr_a = ft_floatcalloc((argc - 1), sizeof(float));
	arr_b = ft_floatcalloc((argc - 1), sizeof(float));
	originalarr = ft_floatcalloc((argc - 1), sizeof(float));
	if (!arr_a)
		return (0);
	if (!arr_b)
		return (0);
	while (i < argc - 1)
	{
		arr_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	find_zero(&arr_a, argc, 3);
	i = 0;
	while (i < argc - 1)
	{
		originalarr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	while (check_stack_order(&arr_a, argc, 3) != 1)
	{
		printf("ORIGINAL STACKS\n");
		print_stacks(arr_a, arr_b, argc);
		comparison_g1(&arr_a, &arr_b, argc, &ops);
		comparison_g2(&arr_a, &arr_b, argc, &ops);
		vueltas++;
	}
	printf("VUELTAS REALIZADAS: %d\n", vueltas);
	printf("OPERACIONES REALIZADAS: %d\n", ops);

	last_chance(&originalarr, &arr_a, &arr_b, argc);

	free (arr_a);
	free (arr_b);
	free (originalarr);

	return (0);
}
