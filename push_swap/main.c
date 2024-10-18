/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:29:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/17 03:01:50 by pamarti2         ###   ########.fr       */
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
	int	auxnum;

	if (stack == 'a')
	{
		auxnum = *arr_a[0];
		(*arr_a)[0] = (*arr_a)[1];
		(*arr_a)[1] = auxnum;
	}
	if (stack == 'b')
	{
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

// void	split_the_stack(float **arr_a, float **arr_b, int argc)
// {
// 	int num;
// 	int i;

// 	printf("SPLITTING ACTION\n");
// 	i = 0;
// 	while(i < ((argc - 1)/2))
// 	{
// 		num = (*arr_a)[0] - (*arr_a)[1];
// 		if ((*arr_b)[0] == 0.5)
// 		{
// 			if (num < 0)
// 			{
// 				wx_to_stack(arr_a, arr_b, 'a');
// 				px_to_stack(arr_a, arr_b, 'b', argc);
// 			}
// 			else
// 				wx_to_stack(arr_a, arr_b, 'a');
// 		}
// 		else
// 		{
// 			if (num < 0 && num < (*arr_a)[0] - (*arr_b)[0])
// 			{
// 				wx_to_stack(arr_a, arr_b, 'a');
// 				px_to_stack(arr_a, arr_b, 'b', argc);
// 				wx_to_stack(arr_a, arr_b, 'b');
// 				px_to_stack(arr_a, arr_b, 'a', argc);
// 				wx_to_stack(arr_a, arr_b, 'a');
// 				printf("NUEVA MEDIDA\n");
// 			}
// 			else if (num < 0 && num > (*arr_a)[0] - (*arr_b)[0])
// 			{
// 				if ((*arr_a)[1] <)
// 				rx_to_stack(arr_a, arr_b, 'a', argc);
// 				rx_to_stack(arr_a, arr_b, 'a', argc);
// 			}
// 			else if (num > 0)
// 				wx_to_stack(arr_a, arr_b, 'a');

// 		}
// 		i++;
// 	}
// }

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
			print_stacks(*arr_a, *arr_b, argc);
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
			print_stacks(*arr_a, *arr_b, argc);
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
			print_stacks(*arr_a, *arr_b, argc);
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
			print_stacks(*arr_a, *arr_b, argc);
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
			print_stacks(*arr_a, *arr_b, argc);
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
			print_stacks(*arr_a, *arr_b, argc);
		}
		//printf("HOLA\n");
		//print_stacks(*arr_a, *arr_b, argc);
		//i++;
	}
}

int	check_stack_order(float **arr_a, int argc)
{
	int	i;

	i = 0;
	while ((*arr_a)[i] - (*arr_a)[i + 1] < 0)
		i++;
	if (i == argc - 2)
		return (1);
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
float	*take_first_half(float *arr_a, int argc)
{
	float	*first_half;
	int	half_numeric;
	int	i;

	i = 0;
	half_numeric = argc / 2;
	printf("ARGC: %d\n", argc);
	printf("Half Numeric: %d\n", half_numeric);
	first_half = ft_floatcalloc(half_numeric, sizeof(float));
	while (i < half_numeric)
	{
		first_half[i] = arr_a[i];
		i++;
	}
	i = 0;
	printf("Valores de la primera mitad:\n");
	while (i < half_numeric)
	{
		printf("%.1f\n", first_half[i]);
		i++;
	}
	return (first_half);
}

float	*find_index_in_stack(float *originalarr, float *first_half, int argc)
{
	float	*first_half_index;
	int		i;
	int		j;

	i = 0;
	j = 0;
	first_half_index = ft_floatcalloc((argc / 2), sizeof(float));
	if (!first_half)
		return (0);
	while (j < (argc / 2) || i <= (argc / 2))
	{
		// printf("I: %d\n", i);
		// printf("J: %d\n", j);
		//i++;
		if (originalarr[i] == first_half[j])
		{
			//printf("Coincidencia\n");
			first_half_index[j] = i;
			j++;
			if (j == (argc / 2))
				break ;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	printf("Valores de los index de la primera mitad:\n");
	while (i < argc / 2)
	{
		printf("%.1f\n", first_half_index[i]);
		i++;
	}
	return (first_half_index);
}

float	*make_instructions(float **first_half_index, int argc)
{
	float	*instruction_arr;
	int		i;

	i = 0;
	instruction_arr = ft_floatcalloc((argc / 2), sizeof(float));
	// printf("Opcion con argc + 5: %.1f\n", (((*first_half_index)[i - 1] - ((*first_half_index)[i] + (argc - 1)) * -1)));
	// printf("Opcion default:%.1f\n", ((*first_half_index)[i - 1] - (*first_half_index)[i]));
	instruction_arr[i] = 0 - (*first_half_index)[i];
	i++;
	while (i < (argc / 2))
	{
		if (((*first_half_index)[i - 1] - (*first_half_index)[i]) > 0 && ((*first_half_index)[i - 1] - ((*first_half_index)[i] + (argc - 1))) * -1 < ((*first_half_index)[i - 1] - (*first_half_index)[i]))
			instruction_arr[i] = ((*first_half_index)[i - 1] - ((*first_half_index)[i] + (argc - 1)));
		else if (((*first_half_index)[i - 1] - (*first_half_index)[i]) < 0 && (((*first_half_index)[i - 1] + (argc - 1)) - (*first_half_index)[i]) * -1 > ((*first_half_index)[i - 1] - (*first_half_index)[i]))
			instruction_arr[i] = (((*first_half_index)[i - 1] + (argc - 1)) - (*first_half_index)[i]);
		else
			instruction_arr[i] = (*first_half_index)[i - 1] - (*first_half_index)[i];
		i++;
	}
	i = 0;
	while (i < (argc / 2))
	{
		printf("%.1f\n", instruction_arr[i]);
		i++;
	}
	find_zero(&instruction_arr, argc, 2);
	return (instruction_arr);
}

void	choose_the_way(float **originalarr, float **arr_b, float **first_half_index, int argc)
{
	int		move_counter;
	int		j;
	int		x;
	int		procesos;
	int		desviación;
	float	*instructions_f_h;

	instructions_f_h = make_instructions(first_half_index, argc);
	desviación = 0;
	procesos = 0;
	j = 0;
	x = 0;
	printf("Calculando Camino más corto... \n");
	printf("MITAD: %d\n", (argc / 2));
	// hacer gestión del primer número
	while (j < argc / 2) //revisar stop
	{
		move_counter = 0;
		printf("J: %d\n", j);
		printf("move_counter: %d\n", move_counter);
		printf("X: %d\n", x);
		printf("VALOR INSTRUCTION_F_H: %.1f\n", instructions_f_h[j]);
		//printf("Y: %d\n", y);
		if (instructions_f_h[j] < 0)
		{
			printf("Entrando en condición para rotate mov:\n");
			while (move_counter <= (instructions_f_h[j] * -1))
			{
				printf("J: %d\n", j);
				printf("move_counter: %d\n", move_counter);
				if (move_counter == (instructions_f_h[j] * -1))
				{
					px_to_stack(originalarr, arr_b, 'b', argc);
					x++;
					desviación++;
					printf("move_counter: %d\n", move_counter);
					print_stacks(*originalarr, *arr_b, argc);
					printf("push\n");
					procesos++;
					break ;
				}
				else
				{
					rx_to_stack(originalarr, arr_b, 'a', argc); //rotar
					procesos++;
					move_counter++;
					printf("move_counter: %d\n", move_counter);
					print_stacks(*originalarr, *arr_b, argc);
				}
			}
			printf("break done\n");
			printf("Gestionando ceros.\n");
			find_zero(originalarr, argc, 2);
			//move_counter= find_zero(originalarr, argc, 1);
			//printf("move_counterfinal de condición negativa sin corrección: %d\n", move_counter);
			move_counter-= desviación;
			//printf("move_counterfinal de condición negativa corregida: %d\n", move_counter);
		}
		else if (instructions_f_h[j] > 0)
		{
			printf("Entrando en condición para reverse mov:\n");
			//printf("move_counter: %d\n", move_counter);
			while (move_counter <= (instructions_f_h[j]))
			{
				printf("J: %d\n", j);
				printf("Move_counter: %d\n", move_counter);
				printf("X: %d\n", x);
				if (move_counter == (instructions_f_h[j]))
				{
					px_to_stack(originalarr, arr_b, 'b', argc);
					x++;
					desviación++;
					//print_stacks(*originalarr, *arr_b, argc);
					procesos++;
					printf("push\n");
					break ;
				}
				else
				{
					rrx_to_stack(originalarr, arr_b, 'a', argc); //rotar
					procesos++;
					//print_stacks(*originalarr, *arr_b, argc);
				}
				move_counter++;
			}
			move_counter -= desviación;
		}
		else if (instructions_f_h[j] == 0)
		{
			px_to_stack(originalarr, arr_b, 'b', argc);
			x++;
			desviación++;
			//print_stacks(*originalarr, *arr_b, argc);
			procesos++;
			printf("push\n");
		}
		if (instructions_f_h[j + 1] < 0)
			instructions_f_h[j + 1] += desviación;
		else
			instructions_f_h[j + 1] -= desviación;
		desviación = 0;
		j++;
	}
	printf("MOVIMIENTOS: %d\n", procesos);
}

int main(int argc, char **argv) //hacer check para valores numéricos int repetidos en argumentos
{
	int		i;
	//char	*operations[] = {"pb", "pb", "sa", "pa", "pa", "sa"};
	float		*arr_a;
	float		*arr_b;
	int			vueltas = 1;
	int			ops;
	float			*originalarr;
	float		*first_half;
	float		*first_half_index;

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
	i = 0;
	while (i < argc - 1)
	{
		originalarr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	//rrx_to_stack(&arr_a, &arr_b, 'a', argc);
	while (check_stack_order(&arr_a, argc) != 1)
	{
		//print_stacks(arr_a, arr_b, argc);
		printf("ORIGINAL STACKS\n");
		print_stacks(arr_a, arr_b, argc);
		printf("PRIMERA ITERACIÓN: \n");
		comparison_g1(&arr_a, &arr_b, argc, &ops);
		print_stacks(arr_a, arr_b, argc);
		printf("SEGUNDA ITERACIÓN: \n");
		comparison_g2(&arr_a, &arr_b, argc, &ops);
		print_stacks(arr_a, arr_b, argc);
		// comparison_g1(&arr_a, &arr_b, argc, &ops);
		// print_stacks(arr_a, arr_b, argc);
		// comparison_g2(&arr_a, &arr_b, argc, &ops);
		// print_stacks(arr_a, arr_b, argc);
		vueltas++;
	}
	while (check_stack_order(&arr_a, argc) != 1)
	//printf("\033[0;32mLO CONSEGUIMOS!!\033[0m\n\n");
	printf("VUELTAS REALIZADAS: %d\n", vueltas);
	printf("OPERACIONES REALIZADAS: %d\n", ops);

	first_half = take_first_half(arr_a, argc);
	first_half_index = find_index_in_stack(originalarr, first_half, argc);

	choose_the_way(&originalarr, &arr_b, &first_half_index, argc); // en principio bien
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
	free (first_half);
	free (first_half_index);
	return (0);
}
