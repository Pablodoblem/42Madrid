/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:29:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/11 02:09:16 by pamarti2         ###   ########.fr       */
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
		*arr_b[1] = auxnum;
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
		printf("Return de find_zero: %d\n", zero_check);
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
	print_stacks(*arr_a, *arr_b, argc);
}

void	split_the_stack(float **arr_a, float **arr_b, int argc)
{
	int num;
	int i;

	printf("SPLITTING ACTION\n");
	i = 0;
	while(i < ((argc - 1)/2))
	{
		num = (*arr_a)[0] - (*arr_a)[1];
		if (num < 0)
		{
			wx_to_stack(arr_a, arr_b, 'a');
			px_to_stack(arr_a, arr_b, 'b', argc);
		}
		else
			px_to_stack(arr_a, arr_b, 'b', argc);
		i++;
	}
}

void	rx_to_stack(float **arr_a, float **arr_b, char stack, int argc)
{
	int		int_save;
	int		i;
	float	*aux_ptr2arr;

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
	aux_ptr2arr[argc - 2] = int_save;
	print_stacks(*arr_a, *arr_b, argc);

}

void	manage_zeros(float **arr, int argc) // en caso de que haya ceros 
//intercalados estos son sustituidos con los valores más próximos
{
	int	x;
	int zero_pos;

	printf("Manageando ceros\n");
	while (find_zero(arr, argc, 1) != -1)
	{
		zero_pos = find_zero(arr, argc, 1);
		x = zero_pos;
		while ((*arr)[x] == 0.5)
			x++;
		while (x > zero_pos)
		{
			(*arr)[x - 1] = (*arr)[x];
			x--;
		}
	}
}

#include <stdio.h>

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
	while (i < ((argc - 1)/2))
	{
		if (i == ((argc - 1)/2))
			break ;
		if (find_zero(arr_a, argc, 1) != -1)
		{
			manage_zeros(arr_a, argc);
			printf("Ceros manageados...\n");
			find_zero(arr_a, argc, 2);
			print_stacks(*arr_a, *arr_b, argc);
		}
		aux_1 = (*arr_a)[0] - (*arr_b)[0];
		aux_2 = (*arr_a)[0] - (*arr_a)[j];
		printf("J: %d\n", j);
		printf("AUX1: %d\n", aux_1);
		printf("AUX2: %d\n", aux_2);
		printf("Vuelta: %d\n", i + 1);
		//printf("HOLA\n");
		if (aux_1 < 0 && aux_2 < 0 && aux_1 > aux_2) // dos negativos. + -
		{
			printf("A\n");
			rx_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			px_to_stack(arr_a, arr_b, 'a', argc);
			find_zero(arr_a, argc, 2);
			rx_to_stack(arr_a, arr_b, 'a', argc);
		}
		else if (aux_1 < 0 && aux_2 < 0 && aux_1 < aux_2) // dos negativos. - + 
		{
			printf("B\n");
			// if ((*arr_a)[1] == 0.5)
			// {
			// 	px_to_stack(arr_a, arr_b, 'a', argc);
			// 	find_zero(arr_a, argc, 2);
			// 	rx_to_stack(arr_a, arr_b, 'a', argc);
			// 	find_zero(arr_a, argc, 2);
		
			// }
			//else
			//{
				rx_to_stack(arr_a, arr_b, 'a', argc);
				find_zero(arr_a, argc, 2);
				rx_to_stack(arr_a, arr_b, 'a', argc);
				find_zero(arr_a, argc, 2);
				px_to_stack(arr_a, arr_b, 'a', argc);
				find_zero(arr_a, argc, 2);
				rx_to_stack(arr_a, arr_b, 'a', argc);
				find_zero(arr_a, argc, 2);
			//}
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
		}
		else if (aux_1 > 0 && aux_2 > 0 && aux_1 < aux_2) // dos positivos. - +
		{
			printf("E\n");
			wx_to_stack(arr_a, arr_b, 'a');
			rx_to_stack(arr_a, arr_b, 'a', argc);
			rx_to_stack(arr_a, arr_b, 'a', argc);
			px_to_stack(arr_a, arr_b, 'a', argc);
		}
		else if (aux_1 > 0 && aux_2 > 0 && aux_1 > aux_2) // dos positivos. + -
		{
			printf("F\n");
			wx_to_stack(arr_a, arr_b, 'a');
			px_to_stack(arr_a, arr_b, 'a', argc);
			rx_to_stack(arr_a, arr_b, 'a', argc);
			rx_to_stack(arr_a, arr_b, 'a', argc);
		}
		printf("Hola!\n");
		print_stacks(*arr_a, *arr_b, argc);
		i++;
	}
}

int main(int argc, char **argv)
{
	int		i;
	//char	*operations[] = {"pb", "pb", "sa", "pa", "pa", "sa"};
	float		*arr_a;
	float		*arr_b;
	//int		action;

	//action = 1;
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
	if (!arr_a)
		return (0);
	if (!arr_b)
		return (0);
	while(i < argc - 1)
	{
		arr_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	//print_stacks(arr_a, arr_b, argc);
	split_the_stack(&arr_a, &arr_b, argc);
	print_stacks(arr_a, arr_b, argc);
	stack_comparison(&arr_a, &arr_b, argc);
	print_stacks(arr_a, arr_b, argc);

	// rx_to_stack(&arr_a, &arr_b, 'a', argc);
	// print_stacks(arr_a, arr_b, argc);
	// px_to_stack(&arr_a, &arr_b, 'a', argc);
	// print_stacks(arr_a, arr_b, argc);
	// px_to_stack(&arr_a, &arr_b, 'a', argc);
	// print_stacks(arr_a, arr_b, argc);
	// px_to_stack(&arr_a, &arr_b, 'a', argc);
	// print_stacks(arr_a, arr_b, argc);
	// px_to_stack(&arr_a, &arr_b, 'b', argc);
	// rx_to_stack(&arr_a, &arr_b, 'a', argc);
	

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
	return (0);
}
