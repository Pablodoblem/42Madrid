/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:29:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/12/09 14:01:51 by pamarti2         ###   ########.fr       */
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

void	move_the_row(float **arr, int argc, int flag)
{
	int	i;
	int	j;

	i = 0; // 0
	j = i + 1;  // 1
	
	while (j < argc - 1 || i < argc - 1)
		(*arr)[i++] = (*arr)[j++];
	(*arr)[argc - 2] = 0.5;
	//printf("HELLO\n");
	if (flag == 1)
		find_zero(arr, argc, 2); //cuidado con esto que puede haber ceros de argumentos. Manejar próximamanete
}

void	px_to_stack(float **arr_a, float **arr_b, char stack, int argc)
{
	int	i;
	int	j;
	int	zero_check;

	printf("\033[0;32mPUTTING ACTION.\033[0m\n");
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
		move_the_row(arr_b, argc, 1);
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
		move_the_row(arr_a, argc, 1);
	}
	//print_stacks(*arr_a, *arr_b, argc);
}

void	rx_to_stack(float **arr_a, float **arr_b, char stack, int argc)
{
	float	int_save;
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
	if (stack == 'a')
		find_zero_number = find_zero(arr_a, argc, 1);
	else if (stack == 'b')
		find_zero_number = find_zero(arr_b, argc, 1);
	printf("find_zero_number: %d\n", find_zero_number);
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
		printf("int_save: %.1f\n", (*arr_a)[find_zero_number - 1]);
	}
	else
	{
		aux_ptr2arr = *arr_b;
		int_save = (*arr_b)[find_zero_number - 1];
		printf("int_save: %.1f\n", (*arr_b)[find_zero_number - 1]);
	}
	//printf("int_save: %.1f\n", )
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

	//printf("valor de x desde same_num_index : %d\n", x);
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
		// printf("original[i]: %.1f\n", (*originalarr[i]));
		// printf("sorted[j]: %.1f\n", (*sorted[j]));
		//i++;
		printf("Valor de i: %d\n", i);
		printf("Valor de j: %d\n", j);
		if ((*originalarr)[i] == (*sorted)[j])
		{
			printf("Coincidencia\n");
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

void	decrease_numbers(float **arr, int argc, int flag, int index)
{
	int i;
	int	cpy;

	if (index == -1)
		i = 0;
	i = 0;
	if (flag == 1)
	{
		while (i < argc - 1)
		{
			if ((*arr)[i] != 0.5 && (*arr)[i] != 0)
			{
				// if ((*arr)[i] == 0)
				// 	(*arr)[i] = 0.5;
				// else
					(*arr)[i] -= 1;
			}
			i++;
		}
	}
	// else if (flag == 2)
	// {
	// 	cpy = index;
	// 	while (index < ((argc - 1)- (argc / 2)))
	// 	{
	// 		index++;
	// 		if ((*arr)[index] > (*arr)[cpy])
	// 		{
	// 			(*arr)[index] -= 1;
	// 		}
	// 	}
	// }
	else if (flag == 2) //revisar
	{
		while (i < ((argc - 1)- (argc / 2)))
		{
			if ((*arr)[i] > index)
			{
				(*arr)[i] -= 1;
			}
			i++;
		}
	}
	else if (flag == 3)
	{
		cpy = index;
		while (index < ((argc - 1)- (argc / 2)))
		{
			if ((*arr)[index] >= (*arr)[cpy] && (*arr)[index] != 0.5)
			{
				(*arr)[index] -= 1;
			}
			index++;
		}
	}
}
void	increase_numbers(float **arr, int argc, int flag, int index)
{
	int i;
	int	cpy;

	if (index == -1)
		i = 0;
	i = 0;
	if (flag == 1)
	{
		while (i < argc - 1)
		{
			if ((*arr)[i] != 0.5)
			{
				(*arr)[i] += 1;
			}
			i++;
		}
	}
	else if (flag == 2)
	{
		cpy = index;
		while (index < ((argc - 1)- (argc / 2)))
		{
			index++;
			if ((*arr)[index] > (*arr)[cpy])
			{
				(*arr)[index] += 1;
			}
		}
	}
	else if (flag == 3)
	{
		cpy = index;
		while (index < ((argc - 1)- (argc / 2)))
		{
			if ((*arr)[index] >= (*arr)[cpy])
			{
				(*arr)[index] += 1;
			}
			index++;
		}
	}
	else if (flag == 4)
	{
		while (index < ((argc - 1)- (argc / 2)))
		{
			if ((*arr)[index] != 0.5)
				(*arr)[index] += 1;
			index++;
		}
	}
}

int	check_zero(float **arr_c, float **arr_b, int argc, int flag)
{
	int i;
	int	aux_i;
	int	ft;

	ft = 0;
	aux_i = -1;
	i = 0;

	if (flag == 1)
	{
		while (i < argc - 1 && (*arr_b)[0] != 0.5)
		{
			if ((*arr_c)[i] == 0)
			{
				if (ft == 0)
				{
					aux_i = i;
					printf("aux_i: %d\n", aux_i);
					ft = 1;
				}
				else if ((*arr_b)[aux_i] > (*arr_b)[i])
				{
					aux_i = i;
					printf("aux_i: %d\n", aux_i);
				}
				//counter ++;
			}
			i++;
		}
		return (aux_i);
	}
	else if (flag == 2)
	{
		while (i < argc - 1)
		{
			if ((*arr_c)[i] != 0.5)
				break ;
			i++;
		}
		return (0);
	}
	return (-1);
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
	// printf("AUX:\n");
	// i = 0;
	// while (i < argc - 1)
	// {
	// 	printf("%.1f\n", aux[i]);
	// 	i++;
	// }
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
	// int		i;
	// int		j;
	// int		counter;
	// int 	z;
	// float	*aux;

	// aux = ft_floatcalloc(((argc - 1) - (argc / 2)), sizeof(float));
	// counter = 0;
	// j = 0;
	// i = 0;
	// z = 0;
	// while (i < ((argc - 1) - (argc / 2)))
	// {
	// 	aux[i] = (*arr)[i];
	// 	i++;
	// }
	// i = 0;
	// while (z < (argc - 1) - (argc / 2) - 1)
	// {
	// 	j = 0;
	// 	i = 0;
	// 	while (j < ((argc - 1) - (argc / 2)) - 1)
	// 	{
	// 		if (aux[i] - aux [i + 1] < 0)
	// 			counter++;
	// 		if (counter == ((argc - 1) - (argc / 2)) - 1)
	// 			return (1);
	// 		i++;
	// 		j++;
	// 	}
	// 	z++;
	// 	rx_to_stack(&aux, arr_b, 'a', argc);
	// }
	// return (0);

int	arr_c_num_distance(int index, float **arr_c)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (i <= index)
	{
		if ((*arr_c)[i] != 0.5)
			counter++;
		i++;
		printf("plus_aux: %d\n", counter);
	}
	return (counter);
}


// void    s_h_arr_strat(float **originalarr, float **arr_b, float **arr_a, int argc)
// {
//     //float	*sorted_s_h;
// 	float	*sorted_s_h_index;
// 	//float	*target_s_h_index;
// 	//float	*sorted_f_h;
// 	float	*sorted_f_h_index;
// 	float	*sorted_index_arr;
// 	//float	*arr_d = ft_floatcalloc(argc - 1, sizeof(float));
// 	float	*arr_c;
//     int		i;
//     //int		j;
//     int		x;
// 	int		z;
// 	int		w;
// 	int		y;
// 	int		flag;
// 	//int		flax;
// 	//int		instruction;
// 	int		num_check;
// 	int		zero;
// 	int		zero_aux;
// 	int		plus_aux;
// 	int		cpy_argc;
// 	int		moves;

// 	plus_aux = 0;
// 	zero_aux = 0;
// 	moves = 0;
// 	//pos = 0;
// 	cpy_argc = argc - 1;
// 	zero = 0;
// 	flag = 0;
// 	//flax = 0;
// 	z = 0;
// 	x = 0;
//     y = 0;
//    // j = 0;
//     w = 0;
// 	i = 0;
// 	y = 0;

// //-------------------------------------------------------------
// 	printf("ORIGINALARR: \n");
// 	while (w < argc - 1)
// 	{
// 		printf("%.1f\n", (*originalarr)[w]);
// 		w++;
// 	}
// 	w = 0;
// 	sorted_index_arr = make_index(arr_a, originalarr, argc - 1);
// 	printf("SORTED INDEX ARRAY: \n");
// 	while (w < argc - 1)
// 	{
// 		printf("%.1f\n", sorted_index_arr[w]);
// 		w++;
// 	}
// 	sorted_f_h_index = find_halfs_index(sorted_index_arr, argc, 1);
// 	printf("SORTED FIRST HALF INDEX: \n");
// 	w = 0;
// 	while (w < ((argc - 1) - (argc / 2)))
// 	{
// 		printf("%.1f\n", sorted_f_h_index[w]);
// 		w++;
// 	}
// 	sorted_s_h_index = find_halfs_index(sorted_index_arr, argc, 2);
// 	printf("SORTED SECOND HALF INDEX: \n");
// 	w = 0;
// 	while (w < ((argc - 1) - (argc / 2)))
// 	{
// 		printf("%.1f\n", sorted_s_h_index[w]);
// 		w++;
// 	}

// 	printf("Estado inicial: \n");
// 	print_stacks(*originalarr, *arr_b, argc);
// 	arr_c = ft_floatcalloc((argc - 1), sizeof(float));

// //--------------------------------------------------------------

// 	while (i < (argc / 2) && good_order(originalarr, (argc - 1)) == 0)
// 	{

// 		printf("\033[42mCOMIENZO DE BUCLE.\033[0m\n");
// 		printf("Cpy_argc: %d\n", cpy_argc);


// 		num_check = same_num_index(&sorted_s_h_index, argc, x);
// 		if (sorted_f_h_index[i] < 0)
// 		{
// 			sorted_f_h_index[i] += argc - 1;
// 			if ((sorted_f_h_index[i - 1] + 1) > sorted_f_h_index[i])
// 				sorted_f_h_index[i] += 1;
// 			//flag++;
// 		}







// 		while (x == sorted_f_h_index[i] && i < ((argc - 1) - (argc / 2)))
// 		{
// 			printf("\033[1;37;40mCondición de x == sorted_f_h_omdex[x].\033[0m\n");
// 			printf("PUSH X = SORTED_F_H_INDEX[I]\n");
// 			printf("Valor de x: %d\n", x);
// 			px_to_stack(originalarr, arr_b, 'b', argc);
// 			moves++;
// 			cpy_argc--;
// 			sorted_f_h_index[i] += 0.5;
// 			printf("Cpy_argc: %d\n", cpy_argc);
// 			//flax++;                                                    //significa que ha habido push de FH
// 			printf("Decreasing indexes...\n");
// 			decrease_numbers(&sorted_f_h_index, argc, 2, x);
// 			decrease_numbers(&arr_c, argc, 1, x);
// 			decrease_numbers(&sorted_s_h_index, argc, 2, x);
// 			printf("SORTED FIRST HALF INDEX DECREASED: \n");

//  // -----------------------------------------------------------------
// 			w = 0;
// 			while (w < ((argc - 1) - (argc / 2)))
// 			{
// 				printf("%.1f\n", sorted_f_h_index[w]);
// 				w++;
// 			}
// 			printf("SORTED_S_H_INDEX DECREASED: \n");
// 			w = 0;
// 			while (w < ((argc - 1) - (argc / 2)))
// 			{
// 				printf("%.1f\n", sorted_s_h_index[w]);
// 				w++;
// 			}
// 			i++;
// 		}







// 		if (x < sorted_f_h_index[i] && good_order(&sorted_s_h_index, ((argc - 1) - (argc / 2))) == 0 && i < ((argc - 1) - (argc / 2)))
// 		{
// 			printf("\033[1;37;40mCondición de x < sorted_f_h_omdex[x].\033[0m\n");
// 			z = 0;
// 			while (x < sorted_f_h_index[i] && good_order(&sorted_s_h_index, ((argc - 1) - (argc / 2))) == 0)
// 			{
// //--------------------------------------------------------------------
// 				num_check = same_num_index(&sorted_s_h_index, argc, x); //este sobra
// 				printf("num_check: %d, y: %d\n", num_check, y);
// 				printf("Valor de x: %d\n", x);
// 				printf("Valor de y: %d\n", y);
// 				printf("Valor de num_check: %d\n", num_check);
// 				printf("sorted_f_h_i[i]: %.1f\n", sorted_f_h_index[i]);
// 				printf("sorted_s_h_i[y]: %.1f\n", sorted_s_h_index[y]);
// //----------------------------------------------------------------------
// 				while (same_num_index(&sorted_s_h_index, argc, x) != -1) //------------------------------- CONDICIONES
// 				{
// 					printf("sorted_s_h_index[num_check]: %.1f\n", sorted_s_h_index[num_check]);
// 						num_check = same_num_index(&sorted_s_h_index, argc, x);
// 						printf("num_check: %d, y: %d\n", num_check, y);
// 						printf("sorted_s_h_index[num_check - 1] - 1: %.1f\n", sorted_s_h_index[num_check - 1] - 1);
// 						if (num_check != y && num_check > y && x == sorted_s_h_index[num_check])
// 						{
// 							if (sorted_s_h_index[num_check] == sorted_s_h_index[num_check - 1] - 1)
// 							{
// 								wx_to_stack(originalarr, arr_b, 'a');
// 								moves++;
// 								sorted_s_h_index[num_check - 1] += 0.5;
// 								sorted_s_h_index[num_check] += 0.5;
// 								y += 2;
// 							}
// 							else if (sorted_s_h_index[num_check] - sorted_s_h_index[num_check + 1] < 0)
// 							{
// 								sorted_s_h_index[num_check] += 0.5;
// 								sorted_s_h_index[num_check + 1] += 0.5;
// 								y += 2;
// 							}
// 							else if (sorted_s_h_index[num_check] - sorted_s_h_index[num_check + 1] > 0)
// 							{
// 								printf("Valor de z: %d\n", z);
// 								printf("Valor de x: %d\n", x);
// 								//printf("Valor de i: %d\n", i);
// 								printf("\033[0;35mSe ha cumplido la condición 1.\033[0m\n");
// 								px_to_stack(originalarr, arr_b, 'b', argc);
// 								moves++;
// 								cpy_argc--;
// 								printf("Cpy_argc: %d\n", cpy_argc);
// 								sorted_s_h_index[num_check] += 0.5;
// 								flag++;
// 								rx_to_stack(originalarr, arr_b, 'b', argc);
// 								moves++;
// 								w = y; //copia
// 								if (sorted_s_h_index[y] == sorted_s_h_index[num_check - 1] && sorted_s_h_index[y] > sorted_s_h_index[num_check]) //revisar
// 									y += 2;
// 								else
// 									y++;
// 								decrease_numbers(&sorted_f_h_index, argc, 2, x);
// 								printf("Decreasing sh indexes...\n");
// 								decrease_numbers(&sorted_s_h_index, argc, 2, x);
// 								decrease_numbers(&arr_c, argc, 1, i);
// 								printf("Hola1\n");
// 								arr_c[z] = sorted_s_h_index[num_check - 1] - (x - 1);
// 								sorted_s_h_index[num_check - 1] += 0.5;
// 								z++;
// 								//flag++;
// 								printf("Flag: %d\n", flag);

// 	//--------------------------------------------------------------------

// 								printf("SORTED FIRST HALF INDEX DECREASED: \n");
// 								w = 0;
// 								while (w < ((argc - 1) - (argc / 2))) //prints
// 								{
// 									printf("%.1f\n", sorted_f_h_index[w]);
// 									w++;
// 								}
// 								printf("SORTED_S_H_INDEX DECREASED: \n");
// 								w = 0;
// 								while (w < ((argc - 1) - (argc / 2))) //prints
// 								{
// 									printf("%.1f\n", sorted_s_h_index[w]);
// 									w++;
// 								}
// 								w = 0;
// 								printf("ARR_C (dentro del if):\n");
// 								while (w < (argc - 1))
// 								{
// 									printf("%.1f\n", arr_c[w]);
// 									w++;
// 								}

// 	//----------------------------------------------------------------------

// 								while ((zero = check_zero(&arr_c, argc, 1)) != -1) //------------------------------ GESTIÓN DE BUFFER SH DENTRO DE CONDICIÓN
// 								{
// 									printf("\033[1;37;40mCondición Countdown == 0.\033[0m\n");
// 									printf("\033[41mGestionando buffer ... (DENTRO DE CONDICIÓN)\033[0m\n");
// 									zero_aux = zero;
// 									flag--;
// 									printf("flag: %d\n", flag);
// 									printf("Rotando buffer\n");
// 									//while (zero_aux + 1 > 0)
// 									while (zero_aux > 0) // rotate
// 									{
// 										rrx_to_stack(originalarr, arr_b, 'b', argc);
// 										moves++;
// 										zero_aux--;
// 									}
// 									//rx_to_stack(originalarr, arr_b, 'a', argc); -----------contemplar seriamente
// 									px_to_stack(originalarr, arr_b, 'a', argc);
// 									cpy_argc++;
// 									moves++;
// 									printf("Cpy_argc: %d\n", cpy_argc);
// 									increase_numbers(&sorted_f_h_index, argc, 2, i);
// 									increase_numbers(&sorted_s_h_index, argc, 2, i);
// 									printf("SORTED FIRST HALF INDEX INCREASED: \n");
// 									w = 0;
// 									while (w < ((argc - 1) - (argc / 2))) //prints
// 									{
// 										printf("%.1f\n", sorted_f_h_index[w]);
// 										w++;
// 									}
// 									printf("SORTED_S_H_INDEX INCREASED: \n");
// 									w = 0;
// 									while (w < ((argc - 1) - (argc / 2))) //prints
// 									{
// 										printf("%.1f\n", sorted_s_h_index[w]);
// 										w++;
// 									}
// 									w = 0;
// 									printf("ARR_C :\n");
// 									while (w < (argc - 1))
// 									{
// 										printf("%.1f\n", arr_c[w]);
// 										w++;
// 									}
// 									w = 0;
// 									printf("ARR_A:\n");
// 									while (w < (argc - 1))
// 									{
// 										printf("%.1f\n", (*originalarr)[w]);
// 										w++;
// 									}
// 									printf("\033[0;36mSe ha devuelto un valor del SH buffer a Stack A.\033[0m\n");
// 									while (zero - 1 > 0) //reverse rotate
// 									{
// 										rx_to_stack(originalarr, arr_b, 'b', argc);
// 										moves++;
// 										zero--;
// 									}
// 								}
// 							}
// 						}
// 						else if (num_check == y)
// 						{
// 							if (flag > 0)
// 							{
// 								px_to_stack(originalarr, arr_b, 'b', argc);
// 								moves++;
// 								decrease_numbers(&sorted_f_h_index, argc, 2, x);
// 								printf("Decreasing sh indexes...\n");
// 								decrease_numbers(&sorted_s_h_index, argc, 2, x);
// 								decrease_numbers(&arr_c, argc, 1, i);
// 								printf("Hola2\n");
// 								arr_c[z] = arr_c[z - 1];
// 								z++;
// 								y++;
// 								sorted_s_h_index[num_check] += 0.5;
// 							}
// 							// else if (sorted_s_h_index[num_check + 1] == x) // Creo que esto no hace nada
// 							// {
// 							// 	wx_to_stack(originalarr, arr_b, 'a');
// 							// 	moves++;
// 							// 	sorted_s_h_index[num_check] += 0.5;
// 							// 	sorted_s_h_index[num_check + 1] += 0.5;
// 							// 	y += 2;
// 							// }
// 							else
// 							{
// 								printf("HOLA\n");
// 								y++;
// 								sorted_s_h_index[num_check] += 0.5;
// 								break ;
// 							}
// 						}
// 						else if (num_check < y)
// 							break ;
// 				}
// 				printf("Saliendo del While condicional... \n");
// 				printf("Valor de y: %d\n", y);
// 				printf("Valor de x: %d\n", x);

// 				if (x == sorted_f_h_index[i])
// 					break ;
// 				decrease_numbers(&arr_c, argc, 1, x);
// 				w = 0;
// 				print_stacks(*originalarr, *arr_b, argc);
// 				printf("ARR_C:\n");
// 				while (w < (argc - 1))
// 				{
// 					printf("%.1f\n", arr_c[w]);
// 					w++;
// 				}
// 				while ((zero = check_zero(&arr_c, argc, 1)) != -1) //---------------------------------------------- GESTIÓN DE BUFFER SH
// 				{
// 					printf("\033[1;37;40mCondición de Countdown después de main condition.\033[0m\n");
// 					printf("zero = %d\n", zero);
// 					printf("\033[41mGestionando buffer...\033[0m\n");
// 					// if (zero == flag - 1)
// 					zero_aux = zero;
// 					plus_aux = arr_c_num_distance(zero, &arr_c) + 1;
// 					zero = zero_aux;
// 					printf("zero = %d\n", zero);
// 					printf("zero_aux = %d\n", zero_aux);
// 					//zero = zero_aux;
// 					flag--;
// 					printf("plus_aux: %d\n", plus_aux);
// 					printf("Rotando buffer\n");
// 					while (plus_aux > 0)
// 					{
// 						rrx_to_stack(originalarr, arr_b, 'b', argc);
// 						moves++;
// 						plus_aux--;
// 					}
// 					rx_to_stack(originalarr, arr_b, 'a', argc);
// 					moves++;
// 					x++; //importante
// 					printf("Valor de x: %d\n", x);
// 					print_stacks(*originalarr, *arr_b, argc);
// 					px_to_stack(originalarr, arr_b, 'a', argc);
// 					moves++;
// 					cpy_argc++;
// 					printf("Cpy_argc: %d\n", cpy_argc);
// 					increase_numbers(&sorted_f_h_index, argc, 3, x);
// 					increase_numbers(&sorted_s_h_index, argc, 3, x);
// 					printf("\033[0;36mSe ha devuelto un valor del SH buffer a Stack A.\033[0m\n");
// 					printf("Valor de x: %d\n", x);
// 					printf("Valor de y: %d\n", y);
// 					printf("SORTED FIRST HALF INDEX INCREASED: \n");
// 					w = 0;
// 					while (w < ((argc - 1) - (argc / 2))) //prints
// 					{
// 						printf("%.1f\n", sorted_f_h_index[w]);
// 						w++;
// 					}
// 					printf("SORTED_S_H_INDEX INCREASED: \n");
// 					w = 0;
// 					while (w < ((argc - 1) - (argc / 2))) //prints
// 					{
// 						printf("%.1f\n", sorted_s_h_index[w]);
// 						w++;
// 					}
// 					w = 0;
// 					//print_stacks(*originalarr, *arr_b, argc);
// 					printf("ARR_C:\n"); //revisar
// 					while (w < (argc - 1))
// 					{
// 						printf("%.1f\n", arr_c[w]);
// 						w++;
// 					}
// 					while (zero > 0)
// 					{
// 						rx_to_stack(originalarr, arr_b, 'b', argc);
// 						moves++;
// 						zero--;
// 					}
// 					z--;
// 				}
// 				printf("Rotación normal\n");
// 				rx_to_stack(originalarr, arr_b, 'a', argc); //acción de rotación hacia valor FH
// 				moves++;
// 				x++;
// 				printf("Valor de x: %d\n", x);
// 				print_stacks(*originalarr, *arr_b, argc);
// 				//x++;
// 			} // ----------------------------------------------------------------------------------------- FINAL DE BUCLE
// 			printf("Valor de x: %d\n", x);
// 			printf("Valor de i: %d\n", i);
// 			printf("PUSHEANDO FH: \n");
// 			printf("Flag: %d\n", flag);
// 			sorted_f_h_index[i] += 0.5;
// 			px_to_stack(originalarr, arr_b, 'b', argc); // ------------------------------------------------ PUSH ORDINARIO A STACK A
// 			moves++;
// 			cpy_argc--;
// 			printf("Cpy_argc: %d\n", cpy_argc);
// 			i++;
// 			// if (x == cpy_argc - 1)
// 			// {
// 			// 	printf("SE cumplió la condicion x == cpy_argc - 1\n");
// 			// 	x = 1;
// 			// 	//decrease_numbers(&arr_c, argc, 1, x);
// 			// }
// 			printf("Valor de x: %d\n", x);
// 			printf("Decreasing indexes...\n");
// 			decrease_numbers(&sorted_f_h_index, argc, 2, x);
// 			decrease_numbers(&sorted_s_h_index, argc, 2, x);
// 			decrease_numbers(&arr_c, argc, 1, x);
// 			printf("SORTED FIRST HALF INDEX DECREASED: \n");
// 			w = 0;
// 			while (w < ((argc - 1) - (argc / 2))) //prints
// 			{
// 				printf("%.1f\n", sorted_f_h_index[w]); 
// 				w++;
// 			}
// 			printf("SORTED SECOND HALF INDEX DECREASED: \n");
// 			w = 0;
// 			while (w < ((argc - 1) - (argc / 2))) //prints
// 			{
// 				printf("%.1f\n", sorted_s_h_index[w]);
// 				w++;
// 			}
// 			w = 0;
// 			printf("ARR_C (dentro del if):\n");
// 			while (w < (argc - 1))
// 			{
// 				printf("%.1f\n", arr_c[w]);
// 				w++;
// 			}
// 			if (x == cpy_argc)
// 				x = 0;
// 			// while (check_zero(&arr_c, argc, 2) != 0)
// 			// {
// 			// 	if ((zero = check_zero(&arr_c, argc, 1)) != -1) //---------------------------------------------- GESTIÓN DEL AFTER BUFFER SH
// 			// 	{
// 			// 		printf("Gestión de buffer\n");
// 			// 		zero_aux = zero;
// 			// 		printf("Rotando buffer\n");
// 			// 		while (zero_aux > 0)
// 			// 		{
// 			// 			rrx_to_stack(originalarr, arr_b, 'b', argc);
// 			// 			zero_aux--;
// 			// 		}
// 			// 		px_to_stack(originalarr, arr_b, 'a', argc);
// 			// 		increase_numbers(&sorted_f_h_index, argc, 3, i);
// 			// 		increase_numbers(&sorted_s_h_index, argc, 3, i);
// 			// 		printf("\033[0;36mSe ha devuelto un valor del SH buffer a Stack A.\033[0m\n");
// 			// 		while (zero - 1 > 0)
// 			// 		{
// 			// 			rx_to_stack(originalarr, arr_b, 'b', argc);
// 			// 			zero--;
// 			// 		}
// 			// 	}
// 			// 	rx_to_stack(originalarr, arr_b, 'a', argc);
// 			// 	decrease_numbers(&arr_c, argc, 1, i);
// 			// 	x++;
// 			// }
// 			print_stacks(*originalarr, *arr_b, argc);
// 			// w = 0;
// 			// while (w > y)
// 			// {
// 			// 	if ((int)(sorted_s_h_index[w]*10) % 10 == 0)
// 			// 		sorted_s_h_index[w] += 0.5;
// 			// 	w++;
// 			// }
// 		}









// 		else if (x > sorted_f_h_index[i] && good_order(&sorted_s_h_index, ((argc - 1) - (argc / 2))) == 0 && i < ((argc - 1) - (argc / 2)))
// 		{
// 			printf("\033[1;37;40mCondición de x > sorted_f_h_omdex[x].\033[0m\n");
// 			while (x > sorted_f_h_index[i] && good_order(&sorted_s_h_index, ((argc - 1) - (argc / 2))) == 0)
// 			{
				
// 				printf("Valor de x: %d\n", x);
// 				printf("Valor de i: %d\n", i);
// 				printf("Valor de sorted_f_h_index[i]: %.1f\n", sorted_f_h_index[i]);
// 				rrx_to_stack(originalarr, arr_b, 'a', argc); //acción de reverse rotación hacia valor FH
// 				moves++;
// 				increase_numbers(&arr_c, argc, 4, 0);
// 				w = 0;
// 				printf("ARR_C INCREASED:\n");
// 				while (w < (argc - 1))
// 				{
// 					printf("%.1f\n", arr_c[w]);
// 					w++;
// 				}
// 				x--;
// 			}
// 			printf("Valor de x: %d\n", x);
// 			px_to_stack(originalarr, arr_b, 'b', argc);
// 			moves++;
// 			cpy_argc--;
// 			printf("Cpy_argc: %d\n", cpy_argc);
// 			i++;
// 			//x--;
// 			decrease_numbers(&arr_c, argc, 1, i);
// 			printf("Decreasing fh indexes...\n");
// 			decrease_numbers(&sorted_f_h_index, argc, 2, x);
// 			printf("Decreasing sh indexes...\n");
// 			decrease_numbers(&sorted_s_h_index, argc, 2, x); //revisar
// 			w = 0;
// 			printf("ARR_C DECREASED:\n");
// 			while (w < (argc - 1))
// 			{
// 				printf("%.1f\n", arr_c[w]);
// 				w++;
// 			}
// 			printf("SORTED FIRST HALF INDEX DECREASED: \n");
// 			w = 0;
// 			while (w < ((argc - 1) - (argc / 2)))
// 			{
// 				printf("%.1f\n", sorted_f_h_index[w]);
// 				w++;
// 			}
// 			printf("SORTED SECOND HALF INDEX DECREASED: \n");
// 			w = 0;
// 			while (w < ((argc - 1) - (argc / 2)))
// 			{
// 				printf("%.1f\n", sorted_s_h_index[w]);
// 				w++;
// 			}
// 			if (x == cpy_argc)
// 				x = -1;
// 			print_stacks(*originalarr, *arr_b, argc);

// 			// while (flag > 0)
// 			// {
// 			// 	rx_to_stack(originalarr, arr_b, 'a', argc); //acción de rotación hacia valor FH
// 			// 	decrease_numbers(&arr_c, argc);
// 			// 	if (check_zero(&arr_c, argc) != -1) //check que revisa los decrementos de los movimientos restante SH
// 			// 	{
// 			// 		zero = check_zero(&arr_c, argc);
// 			// 		if (zero == 0)
// 			// 		{
// 			// 			rrx_to_stack(originalarr, arr_b, 'b', argc);
// 			// 			px_to_stack(originalarr, arr_b, 'a', argc);
// 			// 			flag--;
// 			// 		}
// 			// 		else if (zero > 0)
// 			// 		{
// 			// 			while (pos <= zero)
// 			// 			{
// 			// 				rrx_to_stack(originalarr, arr_b, 'b', argc);
// 			// 				pos++;
// 			// 			}
// 			// 			px_to_stack(originalarr, arr_b, 'a', argc);
// 			// 			flag--;
// 			// 			while (pos > 0)
// 			// 			{
// 			// 				rx_to_stack(originalarr, arr_b, 'a', argc);
// 			// 				pos--;
// 			// 			}
// 			// 		}
// 			// 		arr_c[zero] = 0.5;
// 			// 	}
// 			// 	x++;
// 			// }
// 			//i++;
// 			if (x == sorted_f_h_index[i] && i < ((argc - 1) - (argc / 2))) // ------------------------------ MEDIDA PREVENTIVA ANTES DE HACER INCREMENTO DE I++
// 			{
// 				while (x == sorted_f_h_index[i] && i < ((argc - 1) - (argc / 2)))
// 				{
// 					printf("PUSH X = SORTED_F_H_INDEX[I]\n");
// 					px_to_stack(originalarr, arr_b, 'b', argc);
// 					moves++;
// 					cpy_argc--;
// 					printf("Cpy_argc: %d\n", cpy_argc);
// 					//flax++;                                                    //significa que ha habido push de FH
// 					printf("Decreasing indexes...\n");
// 					decrease_numbers(&sorted_f_h_index, argc, 2, i);
// 					decrease_numbers(&arr_c, argc, 1, i);
// 					decrease_numbers(&sorted_s_h_index, argc, 2, i);
// 					printf("SORTED FIRST HALF INDEX DECREASED: \n");

// 					w = 0;
// 					while (w < ((argc - 1) - (argc / 2)))
// 					{
// 						printf("%.1f\n", sorted_f_h_index[w]);
// 						w++;
// 					}
// 					printf("SORTED_S_H_INDEX DECREASED: \n");
// 					w = 0;
// 					while (w < ((argc - 1) - (argc / 2)))
// 					{
// 						printf("%.1f\n", sorted_s_h_index[w]);
// 						w++;
// 					}
// 					i++;
// 				}
// 			}
// 		}
		
// 		// else
// 		// 	i++;
// 	}
// 	if (flag > 0)
// 	{
// 		while (flag > 0)
// 		{
// 			while ((zero = check_zero(&arr_c, argc, 1)) != -1) //---------------------------------------------- GESTIÓN DE BUFFER SH
// 			{
// 				printf("zero != -1\n");
// 				printf("\033[41mGestionando buffer...\033[0m\n");
// 				zero_aux = zero;
// 				flag--;
// 				printf("zero_aux: %d\n", zero_aux);
// 				printf("Rotando buffer\n");
// 				while (zero_aux + 1 > 0)
// 				{
// 					rrx_to_stack(originalarr, arr_b, 'b', argc);
// 					moves++;
// 					zero_aux--;
// 				}
// 				if (cpy_argc != 1 && cpy_argc > 0)
// 					rx_to_stack(originalarr, arr_b, 'a', argc);
// 				moves++;
// 				print_stacks(*originalarr, *arr_b, argc);
// 				px_to_stack(originalarr, arr_b, 'a', argc);
// 				cpy_argc++;
// 				printf("Cpy_argc: %d\n", cpy_argc);
// 				increase_numbers(&sorted_f_h_index, argc, 3, i);
// 				increase_numbers(&sorted_s_h_index, argc, 3, i);
// 				printf("\033[0;36mSe ha devuelto un valor del SH buffer a Stack A.\033[0m\n");
// 				printf("Valor de x: %d\n", x);
// 				printf("Valor de y: %d\n", y);
// 				printf("SORTED FIRST HALF INDEX INCREASED: \n");
// 				w = 0;
// 				while (w < ((argc - 1) - (argc / 2))) //prints
// 				{
// 					printf("%.1f\n", sorted_f_h_index[w]);
// 					w++;
// 				}
// 				printf("SORTED_S_H_INDEX INCREASED: \n");
// 				w = 0;
// 				while (w < ((argc - 1) - (argc / 2))) //prints
// 				{
// 					printf("%.1f\n", sorted_s_h_index[w]);
// 					w++;
// 				}
// 				w = 0;
// 				//print_stacks(*originalarr, *arr_b, argc);
// 				printf("ARR_C INCREASED:\n"); //revisar
// 				while (w < (argc - 1))
// 				{
// 					printf("%.1f\n", arr_c[w]);
// 					w++;
// 				}
// 				while (zero > 0)
// 				{
// 					rx_to_stack(originalarr, arr_b, 'b', argc);
// 					zero--;
// 				}
// 				z--;
// 			}	
// 			rx_to_stack(originalarr, arr_b, 'a', argc);
// 			moves++;
// 			decrease_numbers(&arr_c, argc, 1, i);
// 			printf("Valor de x: %d\n", x);
// 			if (x > 100)
// 				break ;
// 			printf("Valor de flag: %d\n", flag);
// 			x++;
// 		}
// 	}

// // --------------- UNDER CONSTRUCTION ---------------------//


// 	// if ((good_order(originalarr, ((argc - 1) - (argc / 2))) == 0)) // falta cubrir el caso de que flag > 0
// 	// {
// 	// 	float	*originalarr_cpy = ft_floatcalloc(((argc - 1) - (argc / 2)), sizeof(float));
// 	// 	w = 0;
// 	// 	while (w < ((argc - 1) - (argc / 2))) //copy
// 	// 	{
// 	// 		originalarr_cpy[w] = (*originalarr)[w];
// 	// 		w++;
// 	// 	}
// 	// 	printf("ORIGINALARR_CPY: \n");
// 	// 	w = 0;
// 	// 	while (w < ((argc - 1) - (argc / 2))) //print
// 	// 	{
// 	// 		printf("%.1f\n", originalarr_cpy[w]);
// 	// 		w++;
// 	// 	}
// 	// 	//float	*sorted_originalarr = ft_floatcalloc(((argc - 1) - (argc / 2)), sizeof(float));
// 	// 	float	*afteroriginalindex = ft_floatcalloc(((argc - 1) - (argc / 2)), sizeof(float));
// 	// 	while (check_stack_order(&originalarr_cpy, ((argc) - (argc / 2)), 3) != 1)
// 	// 	{
// 	// 		print_stacks(originalarr_cpy, *arr_b, argc);
// 	// 		comparison_g1(&originalarr_cpy, arr_b, ((argc) - (argc / 2)), &flag);
// 	// 		comparison_g2(&originalarr_cpy, arr_b, ((argc) - (argc / 2)), &flag);
// 	// 	}
// 	// 	w = 0;
// 	// 	printf("ORIGINALARR_CPY SORTED:\n");
// 	// 	while (w < ((argc - 1) - (argc / 2))) //print
// 	// 	{
// 	// 		printf("%.1f\n", originalarr_cpy[w]);
// 	// 		w++;
// 	// 	}
// 	// 	afteroriginalindex = make_index(&originalarr_cpy, originalarr, ((argc - 1) - (argc / 2)));
// 	// 	printf("AFTER ORIGINAL INDEX: \n");
// 	// 	w = 0;
// 	// 	i = 0;
// 	// 	y = 0;
// 	// 	x = 0;
// 	// 	while (w < ((argc - 1) - (argc / 2))) //print
// 	// 	{
// 	// 		printf("%.1f\n", afteroriginalindex[w]);
// 	// 		w++;
// 	// 	}
// 	// 	if (good_order(originalarr, ((argc - 1) - (argc / 2))) == 0)
// 	// 	{
// 	// 		while (x < afteroriginalindex[i])
// 	// 		{
// 	// 				while (x == afteroriginalindex[i])
// 	// 				{
// 	// 					rx_to_stack(originalarr, arr_b, 'a', argc);
// 	// 					i++;
// 	// 					x++;
// 	// 				}
// 	// 				rx_to_stack(originalarr, arr_b, 'a', argc);
// 	// 				x++;
// 	// 		}
// 	// 			//else if ()
// 	// 	}
// 	// }
// 	printf("NÚMERO TOTAL DE MOVIMIENTOS: %d\n", moves);
// }

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
}

// int	moves_till_extreme(float **originalarr, float **arr_d, int argc)
// {
// 	int	i;
// 	int	counter1;
// 	int	counter2;
// 	int	result;

// 	result = 0;
// 	i = 0;
// 	counter1 = 0;
// 	counter2 = 0;
// 	while ((*originalarr)[i] != (*arr_d)[0])
// 	{
// 		counter1++;
// 		i++;
// 	}
// 	i = 0;
// 	while ((*originalarr)[i] != (*arr_d)[1])
// 	{
// 		counter2++;
// 		i++;
// 	}
// 	if (counter1 < counter 2)
// 		result = -1;
// 	else
// 		result = 1;


// }

// int	check_ordered_nums_originalarr(float **orderedarr, float **originalarr, int argc, float lowest_num)
// {
// 	int	i;
// 	int	counter;

// 	counter = 0;
// 	i = 0;
// 	while (i < argc - 1)
// 	{
// 		if ((*originalarr)[i] == lowest_num)
// 			break ;
// 		i++;
// 	}
// 	while (counter < argc - 1)
// 	{

// 	}
// }

int	check_bhind_lowest_num(float **originalarr, int argc, float lowest_num, float current_num)
{
	int	i;

	i = 0;
	//printf("---------- FUNCIÓN BHIND ------------:\n");
	//printf("Lowest_num: %.1f\n", lowest_num);
	if (current_num == lowest_num) //revisar condiciones añadir 0.5 o no
		return (-1);
	while (i < argc - 1)
	{
		//printf("originalarr[i] desde check bhind lowest num: %.1f\n", (*originalarr)[i]);
		//printf("current_num: %.2f\n", current_num);
		if ((*originalarr)[i] == lowest_num || (*originalarr)[i] == lowest_num + 0.5) // el número más bajo está primero
		{
			//printf("hey1\n");
			return (-1);
		}
		else if ((*originalarr)[i] == current_num || (*originalarr)[i] == current_num + 0.5) // el número más bajo está después
		{
			//printf("hey2\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_destination(float num, float **sortedarr_a, float **originalarr, int argc, float **arr_b, float lowest_num, int flag, int main_flag)
{
	int	counter;
	int	result;
	int	i;
	int	y;

	i = 0;
	y = 0;
	counter = 0;
	if (flag == 1)
	{
		while (i < argc - 1)
		{
			if ((*originalarr)[i] == num)
				break ;
			i++;
		}
		while (i < argc - 1)
		{
			if ((*originalarr)[i] == lowest_num || (*originalarr)[i] == lowest_num + 0.5)
			{
				//counter--;
				break ;
			}
			printf("Inside counter: %d\n", counter); 
			counter++;
			i++;
		}
		printf("Counter - 1 = %d\n", counter - 1);
		return (counter - 1);
	}
	// Encontrar el índice de `num` en `sortedarr_a`
	else if (flag == 2)
	{
		while (i < argc - 1)
		{
			if ((*sortedarr_a)[i] == num)
			{
				i--;
				break ;
			}
			i++;
		}
		printf("sortedarr_a[i]: %.1f\n", (*sortedarr_a)[i]);
		printf("Originalarr[y]: %.1f\n", (*originalarr)[y]);
		// Buscar en `originalarr` para decidir el destino
		while (y < argc - 1)
		{
			if (main_flag == 0 || main_flag == 1)
			{
				if ((*originalarr)[y] == (*sortedarr_a)[i] || ((*originalarr)[y] - 0.5) == (*sortedarr_a)[i])
				{
					result = check_bhind_lowest_num(originalarr, argc, lowest_num, (*sortedarr_a)[i]);
					printf("---------- FUNCIÓN CHECK DESTINATION ------------:\n");
					printf("result: %d\n", result);
					if (result == -1)
					{
						printf("sortedarr[i]: %.1f\n", (*sortedarr_a)[i]);
						printf("originalarr[i]: %.1f\n", (*originalarr)[i]);
						return (counter + 1);
					}
					else if (result == 1)
					{
						if (((*originalarr)[y] == (*sortedarr_a)[i] + 0.5 || ((*originalarr)[y] - 0.5) == (*sortedarr_a)[i] + 0.5))
							return (counter + 1);
						return (check_destination((*sortedarr_a)[i], sortedarr_a, originalarr, argc, arr_b, lowest_num, 2, main_flag));
					}
				}
			}
			// else if (main_flag == 1)
			// {
			// 	if (((*originalarr)[y] == (*sortedarr_a)[i] || ((*originalarr)[y] - 0.5) == (*sortedarr_a)[i]
			// 			|| (*originalarr)[y] == (*sortedarr_a)[i] + 0.5 || ((*originalarr)[y] - 0.5) == (*sortedarr_a)[i] + 0.5))
			// 		return (counter + 1);
			// }
			counter++;
			y++;
		}

		// Buscar en `arr_b` si no se encuentra en `originalarr`
		y = 0;
		counter = 0;
		if ((*arr_b)[y] != 0.5)
		{
			while (y < argc - 1)
			{
				if ((*arr_b)[y] == (*sortedarr_a)[i])
					return (counter *= -1);
				counter++;
				y++;
			}
		}
	}	
	return (0);
}

int	*make_aux_array(int argc)
{
	int	*aux;

	aux = malloc((argc - 1) * sizeof(int));
	if (aux == NULL)
        return(NULL);
	return (aux);	

}

void	block_ordered_num(float **originalarr, float **arr_b, float **sortedarr, int argc, float lowest_num)
{
	int		i;
	int		y;
	float	*aux;
	int		counter;
	int		x;
	//int		y_aux[] = {0, 0, 0, 0, 0, 0};
	int		*y_aux;
	int		z;
	int		f;
	int		e;
	//int		auxaux;


	
	e = 0;
	z = 0;
	counter = 0;
	i = 0;
	y = 1;
	f = y;
	x = 0;
	//y_aux = y;
	printf("Valor de argc: %d\n", argc);
	printf("Valor de z: %d\n", z);
	printf("Valor de i: %d\n", i);
	y_aux = make_aux_array(argc);
	//auxaux = *y_aux;
	//printf("Valor de auxaux: %d\n", auxaux);
    if (y_aux == NULL)
		exit (1); // NO SE RICK ------------------------------------------
	//y_aux = ft_floatcalloc((argc - 1), sizeof(float));
	while (i < argc - 1)
	{
		y_aux[i] = 0;
		i++;
	}
	i = 0;
	aux = ft_floatcalloc((argc - 1), sizeof(float));
	
	while (i < argc - 1) //función de copia
	{
		aux[i] = (*originalarr)[i];
		i++;
	}
	i = 0;
	while (i < argc - 1) // función de búsqueda de lowest number
	{
		if (aux[0] == lowest_num)
			break ;
		rx_to_stack(&aux, arr_b, 'a', argc);
		i++;
	}
	e = i;
	//printf("Valor de e: %d\n", e);
	i = 0;
	//printf("Valor de aux[i]: %.1f\n", aux[i]);
	while (x < argc - 2) //revisar y registrar opción con mayor número de bloqueos
	{
		y = f;
		//printf("Valor de f: %d\n", f);
		while (i < argc - 1 && y < argc - 1)
		{
			//printf("Valor de sortedarr[y]: %.1f\n", (*sortedarr)[y]);
			//printf("Valor de aux[i]: %.1f\n", aux[i]);
			if (aux[i] == (*sortedarr)[y]) // antes estaba con (*originalarr)[] en vez de aux
			{
				y++;
				counter++;
			}
			i++;
		}
		i = 0;
		y_aux[z] = counter;
		f += 1;
		// printf("Valor de y_aux[z]: %d\n", y_aux[z]);
		// printf("Valor de y: %d\n", y);
		counter = 0;
		z++;
		x++;
	}
	i = 0;
	y = 0;
	x = 0;
	while (i < argc - 1)
	{
		//printf("holax\n");
		//printf("Valor de y_aux[i]: %d\n", y_aux[i]);
		if (y_aux[i] > x)
		{
			y = i;
			x = y_aux[i];
		}
		i++;
	}
    i = 0;
    y++;
	// printf("Valor de y: %d\n", y);
	// printf("Valor de aux[i] de nuevo: %.1f\n", aux[i]);
	// printf("Valor de (*sortedarr)[y]: %.1f\n", (*sortedarr)[y]);
	// printf("Valor de i: %d\n", i);
	while (i < argc - 1) //conociendo
	{
		if (aux[i] == (*sortedarr)[y])
		{
			x = i + e;
			if (x > argc - 2)
				x -= (argc - 1);
			//printf("(*originalarr)[x]: %.1f\n", (*originalarr)[x]);
			if ((*originalarr)[x] != (*sortedarr)[argc - 2])
			    (*originalarr)[x] += 0.5;
			y++;
		}
		i++;
	}
	free (aux);
	free (y_aux);
}

void	last_chance(float **originalarr, float **sortedarr_a, float **arr_b, int argc)
{
	float	*arr_c;
	float	*arr_d;
	int		i;
	int		moves_to_good_order;
	int		moves_to_deposit;
	//float	*sorted_index_arr;
	int		instructions;
	//int		cargo;
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
	//cargo = 0;
	printf("ARR_A ORIGINAL SIN PROCESAR:\n");
	print_stacks(*originalarr, *arr_b, argc);
	// sorted_index_arr = make_index(arr_a, originalarr, argc - 1);
	arr_c = ft_floatcalloc((argc - 1), sizeof(float));
	arr_d = ft_floatcalloc(2, sizeof(float));
	find_extremes(&arr_d, originalarr, argc);
	i = 0;
///-------------------------------------------------///
	while (i < 2)
	{
		printf("%.1f\n", arr_d[i]);
		i++;
	}
///-------------------------------------------------///
	i = 0;
	// while (good_order(*originalarr, *arr_b, argc) == 0)
	// {
	printf("STACKS con blocked nums: \n");
	printf("ARGC: %d\n", argc);
	block_ordered_num(originalarr, arr_b, sortedarr_a, argc, arr_d[0]);
	print_stacks(*originalarr, *arr_b, argc);
	while (y < 16)
	{
		if (good_order(originalarr, arr_b, argc) != -1 && flag == 1)
			break ;
		// printf("good_order: %d, arr_b[0]: %.1f, flag: %d\n", good_order(originalarr, arr_b, argc), (*arr_b)[0], flag);
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
			//decrease_numbers(&arr_c, argc, 1, 0);
			//rx_to_stack(&arr_c, arr_b, 'a', argc);
			//find_zero(&arr_c, argc, 2);
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
			// x = 0;
			// while (x < argc - 1) //print de arr_c
			// {
			// 	printf("%.1f\n", arr_c[x]);
			// 	x++;
			// }
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
			// if ((*originalarr)[1] != arr_d[0] && (*originalarr)[1] != arr_d[0] + 0.5)
			// {
			if (!((*originalarr)[0] == arr_d[1] && (*originalarr)[1] == arr_d[0]))
			{
				if ((*originalarr)[0] == arr_d[1])
				{
					printf("Entrando\n");
					moves_to_deposit = check_destination((*originalarr)[0], sortedarr_a, originalarr, argc, arr_b, arr_d[0], 1, flag) + 1;
					// if (moves_to_deposit == 0)
					// 	moves_to_deposit += 2;		
				}
				else
					moves_to_deposit = check_destination((*originalarr)[0], sortedarr_a, originalarr, argc, arr_b, arr_d[0], 2, flag);
				printf("moves_to_deposit: %d\n", moves_to_deposit);


				zero_check = find_zero(&arr_c, argc, 1);
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
					//printf("arr_c[0] = moves_to_deposit\n");
					arr_c[0] = moves_to_deposit;
					//(*originalarr)[1] += 0.5;
					// if (check_bhind_lowest_num(originalarr, argc, arr_d[0], (*originalarr)[moves_to_deposit - 2]) == -1)
					// {
					// if (flag == 1)
					// {
					// 	if ((!((((*originalarr)[moves_to_deposit - 1]) - (int)(*originalarr)[moves_to_deposit - 1] >= 0.4999)
					// 		&& ((*originalarr)[moves_to_deposit - 1] - (int)(*originalarr)[moves_to_deposit - 1] <= 0.5001))))
					// 	{
					// 		printf("Hola pescao\n");
					// 		printf("(*originalarr)[moves_to_deposit - 1]: %.1f\n", (*originalarr)[moves_to_deposit - 1]);
					// 		//(*originalarr)[moves_to_deposit - 1] += 0.5;
					// 	}
						
					// }
				}

				px_to_stack(originalarr, arr_b, 'b', argc);
				//cargo++;
				instructions++;
				printf("Originalarr:\n");
				print_stacks(*originalarr, *arr_b, argc);
				decrease_numbers(&arr_c, argc, 1, 0);
				// if (!(((*originalarr)[moves_to_deposit - 2]) - (int)(*originalarr)[moves_to_deposit - 2] >= 0.4999) && ((*originalarr)[moves_to_deposit - 2] - (int)(*originalarr)[moves_to_deposit - 2] <= 0.5001) && (*originalarr)[moves_to_deposit - 2] != arr_d[0])
				// 	(*originalarr)[moves_to_deposit - 2] += 0.5;
				
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
				//rx_to_stack(originalarr, arr_b, 'a', argc);
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
	
	
	// s_h_arr_strat(&originalarr, &arr_b, &arr_a, argc);
	// print_stacks(originalarr, arr_b, argc);
	// // rx_to_stack(&arr_a, &arr_b, 'a', argc);
	// // print_stacks(arr_a, arr_b, argc);
	// // wx_to_stack(&arr_a, &arr_b, 'a');
	// // // printf("ACCIÓN nº %d: \n", action);
	// // // action++;
	// // // print_stacks(arr_a, arr_b, argc);
	// // px_to_stack(&arr_a, &arr_b, 'a', argc);
	// // print_stacks(arr_a, arr_b, argc);

// ESTE BLOQUE ES PARA V4 LAST CHANCE  -----------------------------------------------

	last_chance(&originalarr, &arr_a, &arr_b, argc);

	free (arr_a);
	free (arr_b);
	free (originalarr);

	return (0);
}
