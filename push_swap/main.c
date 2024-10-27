/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:29:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/28 00:16:19 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	check_arg_format(int argc, char **argv)
{
	int		i;
	// char	*checkstr;

	// checkstr = malloc()        HACER CHECK PARA NÚMEROS REPETIDOS
	i = 1;
	while (i < argc)
	{
		//printf("Argumento %d: %s\n", i, argv[i]);
		if (ft_isdigitmod(argv[i]) == 1)
			return (1);
		if (ft_strlen(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	print_stacks(float *numarr_a, float *numarr_b, int argc)
{
	int	i;
	
	i = 0;
	printf("STACK A:\n");
	while(i < argc - 1)
	{
		printf("%.1f\n", numarr_a[i]);
		i++;
	}
	i = 0;
	printf("--------------------\n");
	printf("STACK B:\n");
	while(i < argc - 1)
	{
		printf("%.1f\n", numarr_b[i]);
		i++;
	}
	printf("--------------------\n");
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	printf("--------------------\n");
}

void	wx_to_stack(float **arr_a, float **arr_b, char stack)
{
	float	auxnum;

	
	if (stack == 'a')
	{
		printf("SWAPPING A ACTION\n");
		auxnum = *arr_a[0];
		(*arr_a)[0] = (*arr_a)[1];
		(*arr_a)[1] = auxnum;
	}
	if (stack == 'b')
	{
		printf("SWAPPING B ACTION\n");
		auxnum = *arr_b[0];
		(*arr_b)[0] = (*arr_b)[1];
		(*arr_b)[1] = auxnum;
	}
}

int	find_zero(float **arr, int argc, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		while (i < argc - 1)
		{
			if ((*arr)[i] == 0.5)
				return (i);
			i++;
		}
	}
	else if (flag == 2)
	{
		while(i < argc - 1)
		{
			if ((*arr)[i] == 0)
				(*arr)[i] = 0.5;
			//printf("CERO ENCONTRADO -> %.1f\n", (*arr)[i]);
			i++;
		}
	}
	else if (flag == 3)
	{
		while(i < argc - 1)
		{
			if ((*arr)[i] == 0)
			{
				printf("CERO ENCONTRADO -> %.1f\n", (*arr)[i]);
				(*arr)[i] = 0.25;
			}
			printf("Check\n");
			//printf("CERO ENCONTRADO -> %.1f\n", (*arr)[i]);
			i++;
		}
	}
	return (-1);
}

void	move_the_row(float **arr, int argc)
{
	int	i;
	int	j;

	i = 0; // 0
	j = i + 1;  // 1
	while (j < argc - 1 || i < argc - 1)
		(*arr)[i++] = (*arr)[j++];
	(*arr)[argc - 2] = 0.5;
	//printf("HELLO\n");
	find_zero(arr, argc, 2); //cuidado con esto que puede haber ceros de argumentos. Manejar próximamanete
}

void	px_to_stack(float **arr_a, float **arr_b, char stack, int argc)
{
	int	i;
	int	j;
	int	zero_check;

	printf("PUTTING ACTION\n");
	i = argc - 3; // 4
	j = i + 1;
	if (stack == 'a')
	{
		zero_check = find_zero(arr_a, argc, 1);
		//printf("Return de find_zero: %d\n", zero_check);
		if (zero_check != -1)
				i = ((j = zero_check), (j - 1));
		while (j >= 0 || i >= 0)
			(*arr_a)[j--] = (*arr_a)[i--];
		(*arr_a)[0] = (*arr_b)[0];
		move_the_row(arr_b, argc);
		//print_stacks(*arr_a, *arr_b, argc);
	}
	if (stack == 'b')
	{
		zero_check = find_zero(arr_b, argc, 1);
		if (zero_check != -1)
				i = ((j = zero_check), (j - 1));
		while (j >= 0 || i >= 0)
			(*arr_b)[j--] = (*arr_b)[i--];
		(*arr_b)[0] = (*arr_a)[0];
		move_the_row(arr_a, argc);
	}
	//print_stacks(*arr_a, *arr_b, argc);
}

void	rx_to_stack(float **arr_a, float **arr_b, char stack, int argc)
{
	int		int_save;
	int		i;
	float	*aux_ptr2arr;
	int		find_zero_number;

	printf("ROTATING ACTION\n");
	i = 0;
	if (stack == 'a')
	{
		aux_ptr2arr = *arr_a;
		int_save = (*arr_a)[0];
	}
	else
	{
		aux_ptr2arr = *arr_b;
		int_save = (*arr_b)[0];
	}
	while (i < argc - 2)
	{
		aux_ptr2arr[i] = aux_ptr2arr[i + 1];
		i++;
	}
	find_zero_number = find_zero(&aux_ptr2arr, argc, 1);
	//printf("ZERO_NUMBER: %d\n", find_zero_number);
	if (find_zero_number == -1)
		find_zero_number = argc - 2;
	
	aux_ptr2arr[find_zero_number] = int_save; //ultima medida. Rota en el primer 0.5
	//print_stacks(*arr_a, *arr_b, argc);

}

void	splitv2(float **arr_a, float **arr_b, int argc)
{
	int num;
	int i;

	printf("SPLITTING ACTION Nº 2\n");
	i = 0;
	while(i < ((argc - 1)/2))
	{
		num = (*arr_a)[0] - (*arr_a)[1];
		if (num < 0)
		{
			wx_to_stack(arr_a, arr_b, 'a');
			px_to_stack(arr_a, arr_b, 'b', argc);
			rx_to_stack(arr_a, arr_b, 'a', argc);
		}
		else
		{
			px_to_stack(arr_a, arr_b, 'b', argc);
			rx_to_stack(arr_a, arr_b, 'a', argc);
		}
		i++;
	}
	wx_to_stack(arr_a, arr_b, 'b');
	rx_to_stack(arr_a, arr_b, 'b', argc);
	rx_to_stack(arr_a, arr_b, 'b', argc);
}

void	rrx_to_stack(float **arr_a, float **arr_b, char stack, int argc)
{
	int		int_save;
	//int		copy_zero_number;
	float	*aux_ptr2arr;
	int		find_zero_number;
	//int		i = 0;

	printf("REVERSE ROTATING ACTION\n");
	//i = 0;
	// while (i < argc - 1)
	// {
	// 	printf("%.1f\n", (*arr_a)[i]);
	// 	i++;
	// }
	find_zero_number = find_zero(arr_a, argc, 1);
	if (find_zero_number == -1)
	{
		//printf("HEY\n");
		find_zero_number = argc - 2;
	}
	//copy_zero_number = find_zero_number;
	//printf("Zero number: %d\n", find_zero_number);
	if (stack == 'a')
	{
		aux_ptr2arr = *arr_a;
		int_save = (*arr_a)[find_zero_number - 1];
	}
	else
	{
		aux_ptr2arr = *arr_b;
		int_save = (*arr_b)[find_zero_number - 1];
	}
	while (find_zero_number - 2 >= 0)
	{
		aux_ptr2arr[find_zero_number - 1] = aux_ptr2arr[find_zero_number - 2];
		argc--;
		find_zero_number--;
	}
	//find_zero_number = find_zero(&aux_ptr2arr, argc, 1);
	//printf("ZERO_NUMBER: %d\n", find_zero_number);
	//copy_zero_number = 0;
	aux_ptr2arr[0] = int_save; //ultima medida. Rota en el primer 0.5
	//print_stacks(*arr_a, *arr_b, argc);

}

void	manage_zeros(float **arr, int argc) // en caso de que haya ceros 
//intercalados estos son sustituidos con los valores más próximos
{
	int	x;
	int zero_pos;
	int	stop_flag;

	stop_flag = 0;
	while (find_zero(arr, argc, 1) != -1 && stop_flag == 0)
	{
		zero_pos = find_zero(arr, argc, 1);
		x = zero_pos;
		while ((*arr)[x] == 0.5 && x < argc - 2)
			x++;
		while (x > zero_pos)
		{
			(*arr)[x - 1] = (*arr)[x];
			x--;
			if (x == zero_pos)
				stop_flag = 1;
		}
	}
}

void	stack_comparison(float **arr_a, float **arr_b, int argc)
{
	int	i;
	int	aux_1;
	int	aux_2;
	//int	aux_int;
	int	j;
	//int	x;
	//int	zero_pos;
	//int	prueba;

	//prueba = sizeof(*arr_a);
	//printf("Tamaño de array %d\n", prueba);
	printf("Stack Comparison\n");

	i = 0;
	j = 1;
	//x = 1;
	//printf("TOPE: %d\n", ((argc - 1)/2));
	while (i < ((argc - 1)/2))
	{
		//printf("VALOR DE i: %d\n", i);
		if (i == ((argc - 1)/2))
			break ;
		// if (find_zero(arr_a, argc, 1) != -1)
		// {
		// 	//printf("HOLA!\n");
		// 	//manage_zeros(arr_a, argc);
		// 	//printf("Ceros manageados...\n");
		// 	//find_zero(arr_a, argc, 2);
		// 	print_stacks(*arr_a, *arr_b, argc);
		// }
		aux_1 = (*arr_a)[0] - (*arr_b)[0];
		aux_2 = (*arr_a)[0] - (*arr_a)[j];
		// printf("J: %d\n", j);
		// printf("AUX1: %d\n", aux_1);
		// printf("AUX2: %d\n", aux_2);
		// printf("Vuelta: %d\n", i + 1);
		//printf("HOLA\n");
		if (aux_1 < 0 && aux_2 < 0 && aux_1 > aux_2) // dos negativos. + -
		{
			printf("A\n");
			rx_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			px_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			rx_to_stack(arr_a, arr_b, 'a', argc);
			i++;
			printf("Procesos: %d\n", i);
			if (!(i < ((argc - 1)/2)))
				break ;
			//print_stacks(*arr_a, *arr_b, argc);
		}
		else if (aux_1 < 0 && aux_2 < 0 && aux_1 < aux_2) // dos negativos. - + 
		{
			printf("B\n");
			rx_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			rx_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			px_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			rx_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			i++;
			printf("Procesos: %d\n", i);
			if (!(i < ((argc - 1)/2)))
				break ;
			//print_stacks(*arr_a, *arr_b, argc);
		}
		else if (aux_1 < 0 && aux_2 > 0) // negativo positivo
		{
			printf("C\n");
			rx_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			px_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			rx_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			i++;
			printf("Procesos: %d\n", i);
			if (!(i < ((argc - 1)/2)))
				break ;
			//print_stacks(*arr_a, *arr_b, argc);
		}
		else if (aux_1 > 0 && aux_2 < 0) // positivo negativo
		{
			printf("D\n");
			rx_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			px_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			rx_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			i++;
			printf("Procesos: %d\n", i);
			if (!(i < ((argc - 1)/2)))
				break ;
			//print_stacks(*arr_a, *arr_b, argc);
		}
		else if (aux_1 > 0 && aux_2 > 0 && aux_1 < aux_2) // dos positivos. - +
		{
			printf("E\n");
			wx_to_stack(arr_a, arr_b, 'a');
			rx_to_stack(arr_a, arr_b, 'a', argc);
			rx_to_stack(arr_a, arr_b, 'a', argc);
			px_to_stack(arr_a, arr_b, 'a', argc);
			i++;
			printf("Procesos: %d\n", i);
			if (!(i < ((argc - 1)/2)))
				break ;
			//print_stacks(*arr_a, *arr_b, argc);
		}
		else if (aux_1 > 0 && aux_2 > 0 && aux_1 > aux_2) // dos positivos. + -
		{
			printf("F\n");
			wx_to_stack(arr_a, arr_b, 'a');
			px_to_stack(arr_a, arr_b, 'a', argc);
			rx_to_stack(arr_a, arr_b, 'a', argc);
			rx_to_stack(arr_a, arr_b, 'a', argc);
			i++;
			printf("Procesos: %d\n", i);
			if (!(i < ((argc - 1)/2)))
				break ;
			//print_stacks(*arr_a, *arr_b, argc);
		}
		//printf("HOLA\n");
		//print_stacks(*arr_a, *arr_b, argc);
		//i++;
	}
}

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
		while ((*arr_a)[i] - (*arr_a)[i + 1] < 0)
			i++;
		if (i == argc - 2)
			return (1);
	}
	return (0);
}

void	comparison_g1(float **arr_a, float **arr_b, int argc, int *ops)
{
	int	i;
	int	num;

	i = 0;
	printf("ARGC: %d\n", argc);
	while (i < argc - 2)
	{
		num = (*arr_a)[0] - (*arr_a)[1];
		printf("Valor de la resta: %d\n", num);
		if (((*arr_a)[0] - (*arr_a)[1]) > 0)
		{
			wx_to_stack(arr_a, arr_b, 'a');
			printf("Permutando números...\n");
			print_stacks(*arr_a, *arr_b, argc);
			(*ops)++;
			//print_stacks(*arr_a, *arr_b, argc);
		}
		i += 2;
		rx_to_stack(arr_a, arr_b, 'a', argc);
		rx_to_stack(arr_a, arr_b, 'a', argc);
		printf("Tras rotar\n");
		print_stacks(*arr_a, *arr_b, argc);
		(*ops) += 2;
		printf("Valor I (primera iteración): %d\n", i);
	}
	if ((argc - 1) % 2 != 0)
		rx_to_stack(arr_a, arr_b, 'a', argc);
	printf("EStado de salida de los stacks:\n");
	print_stacks(*arr_a, *arr_b, argc);
}

void	comparison_g2(float **arr_a, float **arr_b, int argc, int *ops)
{
	int	i;
	int	num;

	i = 1;
	printf("ARGC: %d\n", argc);
	rx_to_stack(arr_a, arr_b, 'a', argc);
	(*ops)++;
	while (i < argc - 2)
	{
		if ((argc - 1) % 2 == 0)
		{
			printf("hola\n");
			if (i >= argc - 2)
				break ;
		}
		num = (*arr_a)[0] - (*arr_a)[1];
		printf("Valor de la resta: %d\n", num);
		if (((*arr_a)[0] - (*arr_a)[1]) > 0)
		{
			wx_to_stack(arr_a, arr_b, 'a');
			printf("Permutando números...\n");
			print_stacks(*arr_a, *arr_b, argc);
			//printf("HOLA\n");
			(*ops)++;
			//print_stacks(*arr_a, *arr_b, argc);
		}
		i += 2;
		rx_to_stack(arr_a, arr_b, 'a', argc);
		rx_to_stack(arr_a, arr_b, 'a', argc);
		printf("Tras rotar\n");
		print_stacks(*arr_a, *arr_b, argc);
		(*ops) += 2;
		printf("Valor I (segunda iteración): %d\n", i);
	}
	// if (((*arr_a)[0] - (*arr_a)[1]) > 0)
	// 	wx_to_stack(arr_a, arr_b, 'a');
	if ((argc - 1) % 2 == 0)
		rx_to_stack(arr_a, arr_b, 'a', argc);
	printf("EStado de salida de los stacks:\n");
	print_stacks(*arr_a, *arr_b, argc);
}
float	*take_a_half(float *arr_a, int argc, int flag)
{
	float	*half;
	int	half_numeric;
	int	i;

	i = 0;
	half_numeric = argc / 2;
	printf("ARGC: %d\n", argc);
	printf("Half Numeric: %d\n", half_numeric);
	if (flag == 1)
	{
		half = ft_floatcalloc(half_numeric, sizeof(float));
		while (i < half_numeric)
		{
			half[i] = arr_a[i];
			i++;
		}
	}
	else if (flag == 2)
	{
		half = ft_floatcalloc(((argc - 1) - half_numeric), sizeof(float));
		while (half_numeric < argc - 1)
		{
			half[i] = arr_a[half_numeric];
			half_numeric++;
			i++;
		}
	}
	// i = 0;
	// printf("Valores de la primera mitad:\n");
	// while (i < ((argc - 1) - (argc / 2)))
	// {
	// 	printf("%.1f\n", half[i]);
	// 	i++;
	// }
	return (half);
}

float	*find_halfs_index(float *index_arr, int argc, int flag)
{
	float	*halfs_index;
	int		i;

	i = 0;
	halfs_index = ft_floatcalloc((argc / 2), sizeof(float));
	if (flag == 1)
	{
		halfs_index = ft_floatcalloc((argc / 2), sizeof(float));
		while (i < (argc / 2))
		{
			halfs_index[i] = index_arr[i];
			i++;
		}
		return (halfs_index);
	}
	else if (flag == 2)
	{
		halfs_index = ft_floatcalloc(((argc - 1) - (argc / 2)), sizeof(float));
		while (i < ((argc - 1) - (argc / 2)))
		{
			halfs_index[i] = index_arr[(argc / 2) + i];
			i++;
		}
		return (halfs_index);
	}
	return (NULL);
}

// float	*find_halfs_index(float *originalarr, float *first_half, int argc, int flag)
// {
// 	float	*halfs_index;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	if (flag == 1)
// 	{
// 		halfs_index = ft_floatcalloc((argc / 2), sizeof(float));
// 		while (j < (argc / 2) || i <= (argc / 2))
// 		{
// 			// printf("I: %d\n", i);
// 			// printf("J: %d\n", j);
// 			//i++;
// 			if (originalarr[i] == first_half[j])
// 			{
// 				//printf("Coincidencia\n");
// 				halfs_index[j] = i;
// 				j++;
// 				if (j == (argc / 2))
// 					break ;
// 				i = 0;
// 			}
// 			else
// 				i++;
// 		}
// 	}
// 	else if (flag == 2)
// 	{
// 		halfs_index = ft_floatcalloc(((argc - 1) - (argc / 2)), sizeof(float));
// 		while (j < ((argc - 1) - (argc / 2)) || i <= ((argc - 1) - (argc / 2)))
// 		{
// 			// printf("I: %d\n", i);
// 			// printf("J: %d\n", j);
// 			//i++;
// 			if (originalarr[i] == first_half[j])
// 			{
// 				//printf("Coincidencia\n");
// 				halfs_index[j] = i;
// 				j++;
// 				if (j == (argc / 2))
// 					break ;
// 				i = 0;
// 			}
// 			else
// 				i++;
// 		}
// 	}
// 	// i = 0;
// 	// printf("Valores de los index de la primera mitad:\n");
// 	// while (i < ((argc - 1) - (argc / 2)))
// 	// {
// 	// 	printf("%.1f\n", halfs_index[i]);
// 	// 	i++;
// 	// }
// 	return (halfs_index);
// }

float	*make_instructions(float **index_arr, int argc) // jubilar
{
	float	*instruction_arr;
	int		i;

	i = 0;
	instruction_arr = ft_floatcalloc((argc - 1), sizeof(float));
	// printf("Opcion con argc + 5: %.1f\n", (((*first_half_index)[i - 1] - ((*first_half_index)[i] + (argc - 1)) * -1)));
	// printf("Opcion default:%.1f\n", ((*first_half_index)[i - 1] - (*first_half_index)[i]));
	instruction_arr[i] = 0 - (*index_arr)[i];
	i++;
	while (i < argc - 1)
	{
		if (((*index_arr)[i - 1] - (*index_arr)[i]) > 0 && ((*index_arr)[i - 1] - ((*index_arr)[i] + (argc - 1))) * -1 < ((*index_arr)[i - 1] - (*index_arr)[i]))
			instruction_arr[i] = ((*index_arr)[i - 1] - ((*index_arr)[i] + (argc - 1)));
		else if (((*index_arr)[i - 1] - (*index_arr)[i]) < 0 && (((*index_arr)[i - 1] + (argc - 1)) - (*index_arr)[i]) * -1 > ((*index_arr)[i - 1] - (*index_arr)[i]))
			instruction_arr[i] = (((*index_arr)[i - 1] + (argc - 1)) - (*index_arr)[i]);
		else
			instruction_arr[i] = (*index_arr)[i - 1] - (*index_arr)[i];
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		printf("%.1f\n", instruction_arr[i]);
		i++;
	}
	find_zero(&instruction_arr, argc, 2);
	return (instruction_arr);
}

float	make_instructionsv2(float **sorted_arr, float **originalarr, int j, int argc)
{
	int	i;
	int	y;
	int	z;
	int	instructions;

	if (j > 0)
	{
		i = 0;
		y = argc - 2;
		z = 0;
		printf("VALOR QUE BUSCAMOS: %.f\n", (*sorted_arr)[j]);
		while (1)
		{
			if ((*originalarr)[i] == (*sorted_arr)[j])
				break ;
			//printf("VALOR DE original[i]: %.1f\n", (*originalarr)[i]);
			i++;
		}
		while ((*originalarr)[y] == 0.5)
			y--;
		//printf("Valor de y: %d\n", y);
		while (1)
		{
			if ((*originalarr)[y] == (*sorted_arr)[j])
				break ;
			//printf("VALOR DE ORIGINAL[y]: %.1f\n", (*originalarr)[y]);
			y--;
			z++;
		}
		z++;
		printf("Valor de z: %d y valor de i: %d\n", z, i);
		if (i < z || i == z)
			instructions = i * -1;
		else if (z < i)
			instructions = z;
	}
	else
		return (0.5);
	return (instructions);
}

// int	choose_the_way(float **originalarr, float **arr_b, float **index_arr, float **arr_a, int argc)
// {
// 	int		move_counter;
// 	int		j;
// 	//int		x;
// 	// int		i;
// 	// int		y;
// 	// int		z;
// 	int		procesos;
// 	int		flag;
// 	//int		desviación;
// 	float	instructions;
// 	//float	*arr_b;

// 	flag = 0;
// 	instructions = 0 - (*index_arr)[0]; //revisar
// 	procesos = 0;
// 	j = 0;
// 	//x = 0;
// 	printf("Calculando Camino más corto... \n");
// 	printf("PUNTO DE PARTIDA:\n");
// 	print_stacks(*originalarr, *arr_b, argc);
// 	while (j < argc - 1)
// 	{
// 		if (j > 0)
// 			instructions = make_instructionsv2(arr_a, originalarr, j, argc);
// 		move_counter = 0;
// 		printf("\n\n\033[42mVALOR INSTRUCTION: %.1f\033[0m\n\n", instructions);
// 		printf("J: %d\n", j);
// 		//printf("move_counter: %d\n", move_counter);
// 		//printf("X: %d\n", x);
// 		if (instructions < 0)
// 		{
// 			printf("Entrando en condición para rotate mov:\n");
// 			printf("NUMERO TARGET:: %.1f\n", (*arr_a)[j]);
// 			printf("Valor bonus: %.1f\n", (*arr_a)[j + 1]);
// 			while (move_counter <= (instructions * -1))
// 			{
// 				printf("move_counter: %d\n", move_counter);
// 				printf("Valor de original[0]: %.1f\n", (*originalarr)[0]);
// 				printf("J: %d\n", j);
// 				if ((*originalarr)[0] == (*arr_a)[j + 1] && j < argc - 2 && flag == 0)
// 				{
// 					printf("hola1\n");
// 					printf("\033[0;32mVALOR PUSHEADO DESDE PASO MEDIO: %.1f\033[0m\n", (*originalarr)[0]);
// 					px_to_stack(originalarr, arr_b, 'b', argc);
// 					print_stacks(*originalarr, *arr_b, argc);
// 					flag = 1;
// 					instructions += 1;
// 					procesos++;
// 					printf("INSTRUCTIONS: %.1f\n", instructions);
// 					j++;
// 				}
// 				else if (move_counter == (instructions * -1))
// 				{
// 					printf("\033[0;32mVALOR PUSHEADO: %.1f\033[0m\n", (*originalarr)[0]);
// 					px_to_stack(originalarr, arr_b, 'b', argc);
// 					//x++;
// 					print_stacks(*originalarr, *arr_b, argc);
// 					//printf("push\n");
// 					procesos++;
// 					break ;
// 				}
// 				else
// 				{
// 					rx_to_stack(originalarr, arr_b, 'a', argc); //rotar
// 					procesos++;
// 					move_counter++;
// 					//printf("move_counter: %d\n", move_counter);
// 					//print_stacks(*originalarr, *arr_b, argc);
// 				}
// 			}
// 			printf("break done\n");
// 			//printf("Gestionando ceros.\n");
// 			find_zero(originalarr, argc, 2);
// 		}
// 		else if (instructions > 0)
// 		{
// 			move_counter = 0;
// 			printf("Entrando en condición para reverse mov:\n");
// 			printf("NUMERO TARGET:: %.1f\n", (*arr_a)[j]);
// 			printf("Valor de (*arr_a)[j + 1]: %.1f\n", (*arr_a)[j + 1]);
// 			//printf("move_counter: %d\n", move_counter);
// 			while (move_counter <= (instructions))
// 			{
// 				printf("move_counter: %d\n", move_counter);
// 				printf("Valor de original[0]: %.1f\n", (*originalarr)[0]);
// 				printf("J: %d\n", j);
// 				//printf("X: %d\n", x);
// 				if ((*originalarr)[0] == (*arr_a)[j + 1] && j < argc - 2 && flag == 0)
// 				{
// 					printf("hola2\n");
// 					printf("\033[0;32mVALOR PUSHEADO DESDE PASO MEDIO: %.1f\033[0m\n", (*originalarr)[0]);
// 					px_to_stack(originalarr, arr_b, 'b', argc);
// 					print_stacks(*originalarr, *arr_b, argc);
// 					flag = 1;
// 					move_counter--;
// 					procesos++;
// 					//instructions -= 1;
// 					printf("INSTRUCTIONS: %.1f\n", instructions);
// 					j++;
// 				}
// 				else if (move_counter == (instructions))
// 				{
// 					printf("\033[0;32mVALOR PUSHEADO DESDE REVERSE: %.1f\033[0m\n", (*originalarr)[0]);
// 					px_to_stack(originalarr, arr_b, 'b', argc);
// 					//x++;
// 					// desviación++;
// 					print_stacks(*originalarr, *arr_b, argc);
// 					procesos++;
// 					printf("push\n");
// 					break ;
// 				}
// 				else
// 				{
// 					rrx_to_stack(originalarr, arr_b, 'a', argc); //rotar
// 					procesos++;
// 					print_stacks(*originalarr, *arr_b, argc);
// 				}
// 				move_counter++;
// 			}
// 		}
// 		else if (instructions == 0)
// 		{
// 			px_to_stack(originalarr, arr_b, 'b', argc);
// 			//x++;
// 			// desviación++;
// 			//print_stacks(*originalarr, *arr_b, argc);
// 			procesos++;
// 			printf("Se ha pusheado con normalidad valor de instrucción 0push\n");
// 			print_stacks(*originalarr, *arr_b, argc);
// 		}
// 		if (flag == 1)
// 		{
// 			wx_to_stack(arr_a, arr_b, 'b');
// 			flag = 0;
// 			procesos++;
// 		}
// 		// if ((*arr_b)[0] == (*arr_a)[1] && (*arr_b)[1] == (*arr_a)[0])
// 		// {
// 		// 	printf("hey\n");
// 		// 	j += 2;
// 		// // }
// 		// else
// 		j++;
// 	}
// 	return (procesos);
// }

// int    value_coincident(float **index_arr, int argc)
// {
//     int i = 0;
//     while (i < ((argc - 1) - (argc / 2)))
//     {
//         if (unsorted_s_h == num)
//             return (1);
//         i++;
//     }
//     return (0);
// }

int	check_values_same_half(float **arr_b, float **sorted_s_h, int argc)
{
	int	i;
	int	counter;
	int	x;

	x = 0;
	counter = 0;
	i = 0;

	while (i < ((argc - 1) - (argc / 2)))
	{
		if ((*arr_b)[x] == (*sorted_s_h)[i])
		{
			counter++;
			i = 0;
			x++;
			if (counter == 2)
				return (1);
		}
		i++;
	}
	return (0);
}

int	same_num_index(float **sorted_s_h_index, int argc, int x)
{
	int	i;

	i = 0;
	while (i < ((argc - 1) - (argc / 2)))
	{
		if ((*sorted_s_h_index)[i] == x)
			return (i);
		i++;
	}
	return (-1);
}

float	*make_index(float **sorted, float **originalarr, int size)
{
	float	*arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = ft_floatcalloc(size, sizeof(float));
	while (j < size || i <= size)
	{
		// printf("I: %d\n", i);
		// printf("J: %d\n", j);
		//i++;
		if ((*originalarr)[i] == (*sorted)[j])
		{
			//printf("Coincidencia\n");
			arr[j] = i;
			j++;
			if (j == size)
				break ;
			i = 0;
		}
		else
			i++;
	}
	return (arr);
}

void    s_h_arr_strat(float **originalarr, float **arr_b, float **arr_a, int argc)
{
    float	*sorted_s_h;
	float	*sorted_s_h_index;
	//float	*sorted_f_h;
	float	*sorted_f_h_index;
	float	*sorted_index_arr;
    int		i;
    int		j;
    int		x;
	int		z;
	int		w;
	int		y;
	int		flag;
	//int		instruction;
	int		num_check;

	flag = 0;
	z = 0;
	x = 0;
    y = 0;
    j = 0;
    w = 0;
	i = 0;
	y = 0;
	printf("ORIGINALARR: \n");
	while (w < argc - 1)
	{
		printf("%.1f\n", (*originalarr)[w]);
		w++;
	}
	w = 0;
	sorted_index_arr = make_index(arr_a, originalarr, argc - 1);
	printf("SORTED INDEX ARRAY: \n");
	while (w < argc - 1)
	{
		printf("%.1f\n", sorted_index_arr[w]);
		w++;
	}
	//sorted_f_h = take_a_half(sorted_index_arr, argc, 1);
	sorted_s_h = take_a_half(sorted_index_arr, argc, 2);
	printf("SORTED SECOND HALF: \n");
	w = 0;
	while (w < ((argc - 1) - (argc / 2)))
	{
		printf("%.1f\n", sorted_s_h[w]);
		w++;
	}
	sorted_f_h_index = find_halfs_index(sorted_index_arr, argc, 1);
	printf("SORTED FIRST HALF INDEX: \n");
	w = 0;
	while (w < ((argc - 1) - (argc / 2)))
	{
		printf("%.1f\n", sorted_f_h_index[w]);
		w++;
	}
	sorted_s_h_index = find_halfs_index(sorted_index_arr, argc, 2);
	printf("SORTED SECOND HALF INDEX: \n");
	w = 0;
	while (w < ((argc - 1) - (argc / 2)))
	{
		printf("%.1f\n", sorted_s_h_index[w]);
		w++;
	}

	printf("Estado inicial: \n");
	print_stacks(*originalarr, *arr_b, argc);

	// while (check_stack_order(originalarr, argc, 1) != 1 && check_stack_order(arr_b, argc, 2) != 1)
	// while (i < (argc / 2))
	// {
		printf("INDEX DE SortFHI: %.1f\n", sorted_f_h_index[i]);
		printf("INDEX DE SortSHI: %.1f\n", sorted_s_h_index[i]);
		if (x < sorted_f_h_index[i]) // x es el indicador de index en el que nos encontramos
		{
			while (x < sorted_f_h_index[i]) // mientras que x no llegue al index que esperamos de la primera mitad (to stack B):
			{
				printf("Valor de x: %d\n", x);
				printf("Valor de num_check: %d\n", num_check);
				num_check = same_num_index(&sorted_s_h_index, argc, x);
				if (num_check == 0 && x == 0)
				{
					px_to_stack(originalarr, arr_b, 'b', argc);
					flag++;
					x++;
					y++;
				}
				if (flag > 0) // aquí conseguimos capturar valores SH intermedios
				{
					if (x == sorted_s_h_index[num_check + y])
					{
						px_to_stack(originalarr, arr_b, 'b', argc);
						y++;
						flag++;
					}
				}
				if (flag > 1 && check_values_same_half(arr_b, &sorted_s_h, argc) == 1) //en caso de haber hecho push a un número de SH se hace +=1 a flag. Se hace check en caso de que haya dos números de SH
				{
					if ((*arr_b)[0] < (*arr_b)[1]) //Si estos números pertenecen al SH se deben de posicionar el mayor "arriba"
						wx_to_stack(arr_a, arr_b, 'b');
				}
				if (x == sorted_s_h_index[num_check] && num_check != -1 && flag == 0 && sorted_f_h_index[i + 1] > sorted_f_h_index[i] && sorted_s_h_index[num_check + 1] > sorted_s_h_index[num_check] && sorted_s_h_index[num_check + 2] > sorted_s_h_index[num_check]) // SI en el camino nos encontramos con un número de la SH lo pickeamos en caso de que el siguiente dentro del sorted_s_h_index sea mayor
				{
					printf("Paso intermedio detectado.\n");
					if (sorted_s_h_index[num_check] - sorted_s_h_index[num_check + 1] != -1) // Si los números de sorted_s_h_index no son "consecutivos" se hace el push, de lo contrario se pasan
					{
						px_to_stack(originalarr, arr_b, 'b', argc);
						flag++; //se añade marcador de haber añadido un número SH
						z = sorted_s_h_index[num_check + 1]; //por comodidad y para liberar la Y que nos interesa
					} 
						y += 2; //índice de sorted_s_h_index
					
				}
				if (flag > 0 && x == (z - 1)) //En caso de encontrarnos por el camino con el índice posterior al pickeado -1, se procede a devolver el número al stack A
				{
					if (flag > 1) // este es para el caso de que haya más números SH metidos. DIcho de otra manera que flag > 1
					{
						px_to_stack(originalarr, arr_b, 'a', argc);
						rx_to_stack(arr_a, arr_b, 'a', argc);
						rx_to_stack(arr_a, arr_b, 'a', argc);
						//y += 2;
						while (flag > 0)
						{
							px_to_stack(originalarr, arr_b, 'a', argc);
							flag--;
							//y++;
						}
						//y++;
					}
					else
					{
						px_to_stack(originalarr, arr_b, 'a', argc);
						flag--; //se quita el marcador de número SH en stack B
						//y += 2;
					}
				}
				rx_to_stack(originalarr, arr_b, 'a', argc); //mientras x no encuentra el índice indicado, se rota de manera reiterada
				x++;
			}
			i++;
			if (flag != 0) // Condición para poder hacer que un FH se pueda pushear evitando pushear un valor SH guardado en Stack B
			{
				int aux = flag;
				while (aux > 0)
				{
					rx_to_stack(arr_a, arr_b, 'b', argc);
					aux--;
				}
				px_to_stack(originalarr, arr_b, 'b', argc);
				while (aux < flag)
				{
					rrx_to_stack(arr_a, arr_b, 'b', argc);
					aux++;
				}
			}
			else
				px_to_stack(originalarr, arr_b, 'b', argc); //aquí está la acción de dejar el FH en stack B
			//i++;
			while (flag > 0) //en caso de que ya se haya llegado al índice donde se ha hecho el push de un número FH a stack A y siga habiendo marcador flag > 1 se procede a buscar el índice para depositar el número SH
			{
				if (x == sorted_f_h_index[i]) // Check para ver si mientras buscamos el lugar donde dejar los números SH encontramos un número FH
				{
					px_to_stack(originalarr, arr_b, 'b', argc);
					i++;
				}
				if (flag > 0 && x == (z - 1))
				{
					if (flag > 1) // este es para el caso de que haya más números SH metidos. DIcho de otra manera que flag > 1
					{
						px_to_stack(originalarr, arr_b, 'a', argc);
						rx_to_stack(arr_a, arr_b, 'a', argc);
						rx_to_stack(arr_a, arr_b, 'a', argc);
						y += 2;
						while (flag > 0)
						{
							px_to_stack(originalarr, arr_b, 'a', argc);
							flag--;
							y++;
						}
						y++;
					}
					else
					{
						px_to_stack(originalarr, arr_b, 'a', argc);
						flag--; //se quita el marcador de número SH en stack B
						y += 2;
					}
				}
				rx_to_stack(arr_a, arr_b, 'a', argc);
				x++;
			}
			//i++;
		}
		else if (x > sorted_f_h_index[i]) // x es el indicador de index en el que nos encontramos
		{
			while (x > sorted_f_h_index[i]) // mientras que x no llegue al index que esperamos de la primera mitad (to stack B):
			{	
				num_check = same_num_index(&sorted_s_h_index, argc, x);
				if (flag > 0 && num_check != -1) // aquí conseguimos capturar valores SH intermedios
				{
					if (x == sorted_s_h_index[num_check + y])
					{
						px_to_stack(originalarr, arr_b, 'b', argc);
						y++;
						flag++;
					}
				}
				if (flag > 1 && check_values_same_half(arr_b, &sorted_s_h, argc) == 1) //en caso de haber hecho push a un número de SH se hace +=1 a flag. Se hace check en caso de que haya dos números de SH
				{
					if ((*arr_b)[0] < (*arr_b)[1]) //Si estos números pertenecen al SH se deben de posicionar el mayor "arriba"
						wx_to_stack(arr_a, arr_b, 'b');
				}
				if (x == sorted_s_h_index[num_check] && num_check != -1 && flag == 0 && sorted_f_h_index[i + 1] < sorted_f_h_index[i] && sorted_s_h_index[num_check + 1] < sorted_s_h_index[num_check] && sorted_s_h_index[num_check + 2] < sorted_s_h_index[num_check]) // SI en el camino nos encontramos con un número de la SH lo pickeamos en caso de que el siguiente dentro del sorted_s_h_index sea mayor
				{
					if (sorted_s_h_index[num_check] - sorted_s_h_index[num_check + 1] != 1) // Si los números de sorted_s_h_index no son "consecutivos" se hace el push, de lo contrario se pasan
					{
						px_to_stack(originalarr, arr_b, 'b', argc);
						flag++; //se añade marcador de haber añadido un número SH
						z = sorted_s_h_index[num_check + 1]; //por comodidad y para liberar la Y que nos interesa
					} 
						y += 2; //índice de sorted_s_h_index
					
				}
				if (flag > 0 && x == (z - 1)) //En caso de encontrarnos por el camino con el índice posterior al pickeado -1, se procede a devolver el número al stack A
				{
					if (flag > 1) // este es para el caso de que haya más números SH metidos. DIcho de otra manera que flag > 1
					{
						px_to_stack(originalarr, arr_b, 'a', argc);
						rx_to_stack(arr_a, arr_b, 'a', argc);
						rx_to_stack(arr_a, arr_b, 'a', argc);
						//y += 2;
						while (flag > 0)
						{
							px_to_stack(originalarr, arr_b, 'a', argc);
							flag--;
							//y++;
						}
						//y++;
					}
					else
					{
						px_to_stack(originalarr, arr_b, 'a', argc);
						flag--; //se quita el marcador de número SH en stack B
						//y += 2;
					}
				}
				rx_to_stack(arr_a, arr_b, 'a', argc); //mientras x no encuentra el índice indicado, se rota de manera reiterada
				x++;
			}
			i++;
			if (flag != 0) // Condición para poder hacer que un FH se pueda pushear evitando pushear un valor SH guardado en Stack B
			{
				int aux = flag;
				while (aux > 0)
				{
					rx_to_stack(arr_a, arr_b, 'b', argc);
					aux--;
				}
				px_to_stack(originalarr, arr_b, 'b', argc);
				while (aux < flag)
				{
					rrx_to_stack(arr_a, arr_b, 'b', argc);
					aux++;
				}
			}
			else
				px_to_stack(originalarr, arr_b, 'b', argc); //aquí está la acción de dejar el FH en stack B
			//i++;
			while (flag > 0) //en caso de que ya se haya llegado al índice donde se ha hecho el push de un número FH a stack A y siga habiendo marcador flag > 1 se procede a buscar el índice para depositar el número SH
			{
				if (x == sorted_f_h_index[i]) // Check para ver si mientras buscamos el lugar donde dejar los números SH encontramos un número FH
				{
					px_to_stack(originalarr, arr_b, 'b', argc);
					i++;
				}
				if (flag > 0 && x == (z - 1))
				{
					if (flag > 1) // este es para el caso de que haya más números SH metidos. DIcho de otra manera que flag > 1
					{
						px_to_stack(originalarr, arr_b, 'a', argc);
						rx_to_stack(arr_a, arr_b, 'a', argc);
						rx_to_stack(arr_a, arr_b, 'a', argc);
						y += 2;
						while (flag > 0)
						{
							px_to_stack(originalarr, arr_b, 'a', argc);
							flag--;
							y++;
						}
						y++;
					}
					else
					{
						px_to_stack(originalarr, arr_b, 'a', argc);
						flag--; //se quita el marcador de número SH en stack B
						y += 2;
					}
				}
				rx_to_stack(arr_a, arr_b, 'a', argc);
				x++;
			}
			//i++;
		// }
		// else if (x > sorted_f_h_index[i])
		// {
		// 	while (x > (*sorted_f_h_index)[i])
		// 	{
		// 		if (flag > 1 && check_values_same_half(arr_b, sorteed_s_h, argc) == 1)
		// 		{
		// 			if ((*arr_b)[0] < (*arr_b)[1])
		// 				wx_to_stack(arr_a, arr_b, 'b');
		// 		}
		// 		if (x == sorted_s_h_index[y] && (*sorted_f_h_index)[i + 1] < (*sorted_f_h_index)[i] && sorted_s_h_index[y + 1] < (*sorted_s_h_index)[y])
		// 		{
		// 			px_to_stack(originalarr, arr_b, 'b', argc);
		// 			flag++;
		// 			y++;
		// 		}
		// 		rrx_to_stack(arr_a, arr_b, 'a', argc);
		// 		x--;
		// 	}
		// 	px_to_stack(originalarr, arr_b, 'b', argc);
		// 	if (flag > 0)
		// 	{
		// 		while (x > ((*sorted_s_h_index)[i + 1] + 1))
		// 		{
		// 			rx_to_stack(arr_a, arr_b, 'a', argc);
		// 			x--;
		// 		}
		// 		px_to_stack(originalarr, arr_b, 'a', argc);
		// 	}
		// 	i++;
		// }
		j++;
	}
	
}

// int	choose_the_wayv3(float **originalarr, float **arr_b, float **index_arr, float **arr_a, int argc)
// {
// 	float	*first_half;
// 	float	*secund_half;

// 	first_half = ft_floatcalloc((argc / 2), sizeof(float));
// 	second_half = ft_floatcalloc(((argc - 1) - (argc / 2)), sizeof(float));
// 	first_half = take_a_half(arr_a, argc, 1);
// 	second_half = take_a_half(arr_a, argc, 2);
// 	s_h_arr_strat()
// 	return (operations);
// }

void	del_index(float **arr, float **arr_b, int index, int argc)
{
	if (index == 0)
	{
		printf("UNO\n");
		(*arr)[0] = 0.5;
		rx_to_stack(arr, arr_b, 'a', argc);
		find_zero(arr, argc, 2);
	}
	if (index == 1)
	{
		printf("DOS\n");
		wx_to_stack(arr, arr_b, 'a');
		(*arr)[0] = 0.5;
		rx_to_stack(arr, arr_b, 'a', argc);
		find_zero(arr, argc, 2);
	}
}

void	choose_the_wayv2(float **originalarr, float **arr_b, float **sorted_astack, int argc)
{
	int	counter;
	int	i;
	int moves;

	moves = 0;
	counter = 0;
	printf("MITAD DE ARGC: %d\n", (argc / 2));
	while (counter < argc - 1)
	{
		printf("counter: %d\n", counter);
		i = 0;
		printf("VALORES DE SORTED: \n"); // print
		while (i < argc - 1)
		{
			printf("%.1f\n", (*sorted_astack)[i]);
			i++;
		}
		i = 0;
		printf("VALORES DE ORIGINAL: \n"); // print
		while (i < argc - 1)
		{
			printf("%.1f\n", (*originalarr)[i]);
			i++;
		}
		i = 0;
		printf("ARR_B: \n"); // print
		while (i < argc - 2)
		{
			printf("%.1f\n", (*arr_b)[i]);
			i++;
		}
		if ((*originalarr)[0] == (*sorted_astack)[0] || (*originalarr)[0] == (*sorted_astack)[1] || (*originalarr)[1] == (*sorted_astack)[0] || (*originalarr)[1] == (*sorted_astack)[1])
		{
			if ((*originalarr)[0] == (*sorted_astack)[0])
			{
				px_to_stack(originalarr, arr_b, 'b', argc);
				del_index(sorted_astack, arr_b, 0, argc);
				counter++;
				moves++;
			}
			else if ((*originalarr)[0] == (*sorted_astack)[1])
			{
				px_to_stack(originalarr, arr_b, 'b', argc);
				del_index(sorted_astack, arr_b, 1, argc);
				counter++;
				moves++;
			}
			else if ((*originalarr)[1] == (*sorted_astack)[0])
			{
				wx_to_stack(originalarr, arr_b, 'a');
				px_to_stack(originalarr, arr_b, 'b', argc);
				del_index(sorted_astack, arr_b, 0, argc);
				counter++;
				moves += 2;
			}
			else if ((*originalarr)[1] == (*sorted_astack)[1])
			{
				wx_to_stack(originalarr, arr_b, 'a');
				px_to_stack(originalarr, arr_b, 'b', argc);
				del_index(sorted_astack, arr_b, 1, argc);
				counter++;
				moves += 2;
			}
		}
		else if ((*originalarr)[0] < (*originalarr)[1])
		{
			rx_to_stack(originalarr, arr_b, 'a', argc);
			moves++;
		}
		else if ((*originalarr)[0] > (*originalarr)[1])
		{
			wx_to_stack(originalarr, arr_b, 'a');
			rx_to_stack(originalarr, arr_b, 'a', argc);
			moves += 2;
		}
	}
	printf("MOVIMIENTOS REALIZADOS: %d\n", moves);
}

void	push_all(float **originalarr, float **arr_b, int argc)
{
	int	counter;

	counter = 0;
	while (counter < argc - 1)
	{
		px_to_stack(originalarr, arr_b, 'a', argc);
		counter++;
	}
}

int main(int argc, char **argv) //hacer check para valores numéricos int repetidos en argumentos
{
	int		i;
	//char	*operations[] = {"pb", "pb", "sa", "pa", "pa", "sa"};
	float		*arr_a;
	float		*arr_b;
	int			vueltas = 1;
	int			ops;
	//float		*s_h_index;
	float		*originalarr;
	//float		*index_arr;
	//int			operations;
	//float		*instructions;
	//float		*first_half;
	//float		*second_half;
	//float		*first_half_index;
	//float		*second_half_index;

	//operations = 0;
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
	//rrx_to_stack(&arr_a, &arr_b, 'a', argc);
	while (check_stack_order(&arr_a, argc, 3) != 1)
	{
		printf("ORIGINAL STACKS\n");
		print_stacks(arr_a, arr_b, argc);
		comparison_g1(&arr_a, &arr_b, argc, &ops);
		comparison_g2(&arr_a, &arr_b, argc, &ops);
		vueltas++;
	}
	//while (check_stack_order(&arr_a, argc) != 1)
	printf("VUELTAS REALIZADAS: %d\n", vueltas);
	printf("OPERACIONES REALIZADAS: %d\n", ops);

	// index_arr = make_index(&arr_a, &originalarr, argc - 1);
	// int f = 0;
	// printf("INDEX_ARR:\n");
	// while (f < ((argc - 1)))
	// {
	// 	printf("%.1f\n", index_arr[f]);
	// 	f++;
	// }
	// instructions = make_instructions(&index_arr, argc);
	// f = 0;
	// printf("INSTrUCTIONS_ARR:\n");
	// while (f < ((argc - 1)))
	// {
	// 	printf("%.1f\n", index_arr[f]);
	// 	f++;
	// }
	//first_half = take_a_half(arr_a, argc, 1);
	//second_half = take_a_half(arr_a, argc, 2);
	//first_half_index = find_halfs_index(originalarr, first_half, argc, 1);
	//second_half_index = find_halfs_index(originalarr, second_half, argc, 2);

// ESTE BLOQUE ES PARA V1 -----------------------------------------

	// operations = choose_the_way(&originalarr, &arr_b, &index_arr, &arr_a, argc); // en principio bien
	// push_all(&originalarr, &arr_b, argc);
	// print_stacks(originalarr, arr_b, argc);
	// printf("MOVIMIENTOS TOTALES REALIZADOS: %d\n", (operations));
	// printf("\033[0;32mLO CONSEGUIMOS!!\033[0m\n\n");

// ESTE BLOQUE ES PARA V2 ----------------------------------------

	// printf("ORIGINAL STACK ANTES DE CHOOSEV2:\n");
	// print_stacks(originalarr, arr_b, argc);
	// find_zero(&arr_a, argc, 3);
	// find_zero(&originalarr, argc, 3);
	// choose_the_wayv2(&originalarr, &arr_b, &arr_a, argc);
	// int f = 0;
	// printf("VALORES DE SORTED: \n");
	// while (f < argc - 1)
	// {
	// 	printf("%.1f\n", arr_a[f]);
	// 	f++;
	// }
	// print_stacks(originalarr, arr_b, argc);
	// s_h_index = make_index(&arr_a, &originalarr, ((argc - 1) - (argc / 2)));
	// printf("VALORES DE S_H_INDEX: \n");
	// f = 0;
	// while (f < ((argc - 1) - (argc / 2)))
	// {
	// 	printf("%.1f\n", s_h_index[f]);
	// 	f++;
	// }
	// //choose_the_way(&originalarr, &arr_b, &arr_a, argc);
	// push_all(&originalarr, &arr_b, argc);
	// print_stacks(originalarr, arr_b, argc);
	// printf("MOVIMIENTOS REALIZADOS: %d\n", (argc - 1));

// ESTE BLOQUE ES PARA V3  -----------------------------------------------
	
	
	s_h_arr_strat(&originalarr, &arr_b, &arr_a, argc);
	print_stacks(originalarr, arr_b, argc);
	// rx_to_stack(&arr_a, &arr_b, 'a', argc);
	// print_stacks(arr_a, arr_b, argc);
	// wx_to_stack(&arr_a, &arr_b, 'a');
	// // printf("ACCIÓN nº %d: \n", action);
	// // action++;
	// // print_stacks(arr_a, arr_b, argc);
	// px_to_stack(&arr_a, &arr_b, 'a', argc);
	// print_stacks(arr_a, arr_b, argc);

	free (arr_a);
	free (arr_b);
	free (originalarr);
	//free (first_half);
	//free (first_half_index);
	//free (second_half);
	//free (second_half_index);
	return (0);
}
