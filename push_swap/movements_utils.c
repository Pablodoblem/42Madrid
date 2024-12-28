/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:21:28 by pamarti2          #+#    #+#             */
/*   Updated: 2024/12/28 18:04:32 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	move_the_row(float **arr, int argc, int flag)
{
	int	i;
	int	j;

	i = 0; // 0
	j = i + 1;  // 1
	
	while (j < argc - 1 && i < argc - 1)
	{
		(*arr)[i] = (*arr)[j];
		i++;
		j++;
	}
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
		printf("zero_check stack a: %d\n", zero_check);
		if (zero_check > 0)
		{
			i = ((j = zero_check), (j - 1));
			while (j >= 0 && i >= 0)
				(*arr_a)[j--] = (*arr_a)[i--];
		}
		(*arr_a)[0] = (*arr_b)[0];
		move_the_row(arr_b, argc, 1);
		//print_stacks(*arr_a, *arr_b, argc);
	}
	if (stack == 'b')
	{
		zero_check = find_zero(arr_b, argc, 1);
		printf("zero_check stack b: %d\n", zero_check);
		if (zero_check > 0)
		{
			i = ((j = zero_check), (j - 1));
			while (j >= 0 && i >= 0)
				(*arr_b)[j--] = (*arr_b)[i--];
		}
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



